# Lab Activity 17 - TCP Server

|Grade|Improvements|
|-------|------|
|4 Points|There is a need for more explanation on whether the sentence is grammatically and sematically correct or not.|

## A.	Brief Description Of The TCP Server Activity
This activity focuses on the TCP Server- Client Model. In this activity, we are required to successfully transmit data between a tcp server and client and extending that, to create a server that checks our baxter robot instructions if it is syntactically correct and or semantically correct. 
The instructions are encoded by the client and sent to the server to be checked. The data is parsed by the server and the server performs the checks. The result is then encoded again and transmitted back to the client where the client can view the results.

## B.	Commented Code Showing Server.py & Client.py 
Please refer to the code provided.
### For this section, instead of using the pre-provided tcp-server and client, I referenced code available online and wrote my own version of a tcp client-server in Python.

### Screenshot of working server
![tcp-server-demo](https://i.postimg.cc/cCQ8XzQp/image.png)

### Screenshot of data received client-side
![tcp-client-demo](https://i.postimg.cc/tgyvk0Fj/image.png)