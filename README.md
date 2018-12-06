# Kernel-User_TCP_exchanges
Module and a client in user level, that sends a message to get a reply from the server(module inserted previously in kernel)

After inserting module in the kernel (insmod or by using the ./load.sh script), using the start_server_command.sh will make the module initialize and start running a 
kernel thread which will  create a socket, bind, listen and wait for connections.

In the present code, after kthread starts running it is possible to run after compiling client.c, using the arglist 
f.e ( ./client.out hello) , will make kernel module tserver receive a "hello" and as a consequence user-space app will
receive a "success" that tserver will reply.

After by calling the ./unload.sh script module is removed from the Kernel.

![alt text](https://github.com/NikosMouzakitis/Kernel-User_TCP_exchanges/blob/master/tcpe.png)

