'''
This tcp server utilises the sockets module and encodes/decodes data with the pickle 
module during transmission. The server functions as a mediator for our baxter robot.

Baxter robot that takes in min of 2 arguments, max of 4 arguments which are
from a predefined instruction set and checks if the instruction is in a correct
instruction syntax/semnatics. It then returns an output if the instruction given
was understood or failed.
'''
    
import socket
import sys
import pickle #used for data encoding/decoding during transmission

host = 'localhost'
port = 1234
data_payload = 4096 
#Arbitary value that can be changed, I used a high byte value so no data is cut off.

# Instruction Set Library
time = ['1second','2seconds','5seconds','unlimited']
move = ['left','right','forward','backward','stop']
objects = ['orange','apple','car','bus','diamond']
action = ['recognise','eat','see','lift','drop','fetch']
size = ['small','big','little','massive']
location = ['door','kitchen','table']

# Grouping combos based on row, ie first row only has obj, action, time
combo_0 = [objects, action, time]
combo_1 = [objects,size,action]
combo_2 = [move,time]
combo_3 = [move,time,move,time]
combo_4 = [location,action,objects]

#Necessary as lists with vars cannot be printed as literal strs
combo_lib = [["move","time"],["location","action","object"],["object","action","time"],
             ["objects","size","action"],["move","time","move","time"],]

#Grouping instructions together as main lib
full_library = time + move + objects + action + size + location

# Checks which combination the user is inputing and attaches the str of combo chosen.
def baxter(instruction_set):
    combo=[]
    combo_str = []
    if len(instruction_set) < 2 or len(instruction_set) > 4:
        return("Error #0 - 2 to 4 arguements required!")
    for inst in instruction_set:
        if inst not in full_library:
            return("Error #1 - Instruction is not in library")
    if len(instruction_set) == 2:
        combo = combo_2
        combo_str = combo_lib[0]
    elif instruction_set[0] in location:
        combo = combo_4
        combo_str = combo_lib[1]
    elif instruction_set[0] in objects:
        if instruction_set[1] in action:
            combo = combo_0
            combo_str = combo_lib[2]
        else:
            combo = combo_1
            combo_str = combo_lib[3]
    else:
        combo = combo_3
        combo_str = combo_lib[4]
    return (is_syntactically_right(instruction_set,combo,combo_str))

# Checks if the combo inputed actually matches the instruction lib
# to see if the instruction is syntactically correct
def is_syntactically_right(instruction_set,combo,combo_str):
    for i in range(len(instruction_set)):
        if instruction_set[i] not in combo[i]:
            return(f"Syntax is {combo_str}\nError #2 - Instruction syntactically incorrect")
    return(is_semantically_right(instruction_set))

def is_semantically_right(instruction_set):
    '''Function to check if robot is performing semantically right instructions
    These may be instructions that are syntactically right but are dangerous for our robot. '''
    large_objects = ['car','bus']
    inedible_objects = ['diamond','car','bus']
    dangerous_actions = ['lift','drop','fetch']
    large_size = ['big','massive']
    semantically_right = True
    if 'eat' in instruction_set and any(item in inedible_objects for item in instruction_set):
        semantically_right = False
    elif any(item in dangerous_actions for item in instruction_set) and any(item in large_objects for item in instruction_set):
            semantically_right = False
    elif 'kitchen' in instruction_set and any(item in dangerous_actions for item in instruction_set):
        semantically_right = False
    elif any(item in location for item in instruction_set) and any(item in large_size for item in instruction_set):
        semantically_right= False

    if semantically_right == True:
        return ("Instruction syntactically & semantically correct")
    else:
        return ("Instruction syntactically correct, but semantically incorrect")


'''End of baxter robot'''

def bytes_to_list(data):
    #Decodes the bytes from the tcp client into a list object 
    #by using the pickle module
    instruction_set = pickle.loads(data)
    return baxter(instruction_set)

def server(port):
    '''Server takes in list as input, parses it with pickle and performs the checks with out
    baxter robot syntax checker. It the returns if the instruction is understood or failed and
    encodes it back to bytes with pickle to be transmitted back to the client.

    A connection is closed immediately after an instruction is checked.'''
    #Creates a TCP socket with IPV4
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_address = (host, port)
    # Allows the reuse of the same address and port 
    sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1) 
    print ("Starting up baxter server on %s port %s" % server_address)
    #Binds the socket to the port
    sock.bind(server_address)
    # Listens or incoming connections from clients
    sock.listen(1) 
    while True: 
        print ("Waiting to receive message from client")
        client, address = sock.accept() 
        data = client.recv(data_payload) 
        if data:
            print ("Data: %s" %data)
            output = bytes_to_list(data)
            client.send(pickle.dumps(output))
            print ("sent %s bytes back to %s" % (output, address))
        #Ends connection after everything is done
        client.close()
        

if __name__ == '__main__':
    server(port)
  