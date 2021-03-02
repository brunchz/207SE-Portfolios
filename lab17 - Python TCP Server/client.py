'''
TCP client that utilises the socket module to transmit data to the server.
The client takes in an instruction list as input and returns if the instruction given to 
out baxter robot is understood or failed.
'''
import socket 
import sys 
import pickle
import time
 
host = 'localhost' 
port = 1234
def baxter_client(message): 
    #Creates a TCP/IP socket 
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM) 
    #Connects the socket to the server 
    server_address = (host, port) 
    print ("Connecting to %s port %s" % server_address) 
    sock.connect(server_address) 

    #Sends data to our baxter server 
    try: 
        # Send data after encoding to bytes with pickle
        print ("Sending %s" % message)
        sock.sendall(pickle.dumps(message))
        # Wait for the response with arbitary length, used 100 so no data is lost. 
        data = sock.recv(100) 
        print ("Received: %s" % pickle.loads(data)) 
    except socket.error as e: 
        print ("Socket error: %s" %str(e)) 
    except Exception as e: 
        print ("Other exception: %s" %str(e)) 
    finally: 
        print ("Closing connection to the server") 
        sock.close() 

def is_list(message):
    if type(message) != list:
        print("Your instruction has to be a list!")
        print("Correct syntax: ['instruction1','instruction2']...")
    else:
        return baxter_client(message)

def tests():
    #Test that iterates throught the examples to see if the desired outcome is procuded
    test_lib = [['orange','see','1second'],['table','lift','diamond'],['drop','drop'],
    ['left', '2seconds'],['apple','small','eat'],['left','2seconds','forward','1second'],
    ['kitchen','ball','2seconds'],['bus','lift','5seconds'],['car','eat','2seconds'],['left','2seconds','forward','1second'],
    ['apple','small','eat'],['table','lift','diamond'],]

    for i in range(len(test_lib)):
        is_list(test_lib[i])
        print("---------------")
        time.sleep(1) #pauses between transmitting new instructions
            
if __name__ == '__main__': 
   tests()