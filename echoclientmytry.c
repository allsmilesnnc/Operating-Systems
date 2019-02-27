#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <netdb.h>
#include <errno.h>
#include <netinet/in.h>
#include <getopt.h>

/* Be prepared accept a response of this length */
#define BUFSIZE 1033

#define USAGE                                                                       \
    "usage:\n"                                                                      \
    "  echoclient [options]\n"                                                      \
    "options:\n"                                                                    \
    "  -s                  Server (Default: localhost)\n"                           \
    "  -p                  Port (Default: 12041)\n"                                 \
    "  -m                  Message to send to server (Default: \"hello world.\")\n" \
    "  -h                  Show this help message\n"

/* OPTIONS DESCRIPTOR ====================================================== */
static struct option gLongOptions[] = {
    {"server", required_argument, NULL, 's'},
    {"port", required_argument, NULL, 'p'},
    {"message", required_argument, NULL, 'm'},
    {"help", no_argument, NULL, 'h'},
    {NULL, 0, NULL, 0}};

/* Main ========================================================= */
int main(int argc, char **argv)
{
    int option_char = 0;
    char *hostname = "localhost";
    unsigned short portno = 12041;
    char *message = "Hello World!!";

    // Parse and set command line arguments
    while ((option_char = getopt_long(argc, argv, "s:p:m:hx", gLongOptions, NULL)) != -1)
    {
        switch (option_char)
        {
        case 's': // server
            hostname = optarg;
            break;
        case 'p': // listen-port
            portno = atoi(optarg);
            break;
        default:
            fprintf(stderr, "%s", USAGE);
            exit(1);
        case 'm': // message
            message = optarg;
            break;
        case 'h': // help
            fprintf(stdout, "%s", USAGE);
            exit(0);
            break;
        }
    }

    setbuf(stdout, NULL); // disable buffering

    if ((portno < 1025) || (portno > 65535))
    {
        fprintf(stderr, "%s @ %d: invalid port number (%d)\n", __FILE__, __LINE__, portno);
        exit(1);
    }

    if (NULL == message)
    {
        fprintf(stderr, "%s @ %d: invalid message\n", __FILE__, __LINE__);
        exit(1);
    }

    if (NULL == hostname)
    {
        fprintf(stderr, "%s @ %d: invalid host name\n", __FILE__, __LINE__);
        exit(1);
    }

     /* Socket Code Here */

  /* declare the vars */

    char buffer[BUFSIZE];
    const char* server_name = "localhost";
    int aSocket = 0;
    int serverPort = 8888;
    int theSendSize, theRecvSize; //check
    //int theConnection; //check
    //const char theMessage[] = "A Good Day";
    struct sockaddr_in serverAddress;
    memset(&serverAddress, 0, sizeof(serverAddress));
    //struct hostent *server;
    
    struct hostent *he = gethostbyname(server_name);
    unsigned long server_addr_nbo = *(unsigned long *)(he->h_addr_list[0]);

   aSocket = socket(AF_INET, SOCK_STREAM, 0);
    //server = gethostbyname(argv[1]);
  /* error check */
   if (aSocket < 0) {
      fprintf(stderr,"A socket was not created!\n\n");
     exit(1);
   }


 


  /* construct the server socket address */
    //bzero((char *)&serverAddress, sizeof(serverAddress));
    bzero(&serverAddress, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    //bcopy((char *)server->h_addr, 
    //    (char *)&serverAddress.sin_addr.s_addr,
    //     server->h_length);
    //inet_pton(AF_INET, server_name, &serverAddress.sin_addr);
    serverAddress.sin_port = htons(serverPort);
    serverAddress.sin_addr.s_addr = server_addr_nbo; //check //server; //inet_addr("192.168.1.80");
    //memset(serverAddress.sin_zero, '\0', sizeof serverAddress.sin_zero);

 /* set the socket up */

  // Connect socket to server
  if (0 > connect(aSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress))) {
    fprintf(stderr, "client failed to connect!\n");
    close(aSocket);
    exit(1);
  } else {
    fprintf(stdout, "client connected!\n");
  }

 //   aSocket = socket(PF_INET, SOCK_STREAM, 0);
    //server = gethostbyname(argv[1]);
  /* error check */
 //   if (aSocket < 0) {
  //    fprintf(stderr,"A socket was not created!\n\n");
  //    exit(1);
  //  }
  /* connect to server */
    
//    theConnection = connect(aSocket,(struct sockaddr *)&serverAddress,sizeof(serverAddress));
 //   if (theConnection < 0) {
  //     fprintf(stderr,"Could not connect to the server!\n\n");
   //    close(aSocket);
  //     exit(1);
    //}



  /* send message to server */
    theSendSize = send(aSocket, message, strlen(message), 0);
    /* the message has to be greater than size 0 else it did not send */
    if (theSendSize < 0) {
       fprintf(stderr,"The echo message was not sent to the server!\n\n");
       close(aSocket);
       exit(1);
    }



  /* handel the message that came back from the server */
     bzero(buffer,BUFSIZE);
     char* pbuffer = buffer;
     theRecvSize = 0;
     theRecvSize = read(aSocket,buffer,BUFSIZE);
     int n = 0, maxlen = 100, len = 0;
     int n = 0, maxlen = 100, len = 0;
     if (theRecvSize < 0) {
       fprintf(stderr,"The echo message was not received from the server!\n\n");
       close(aSocket);
       exit(1);
    } else 
      while ((n = recv(aSocket, pbuffer, maxlen, 0)) > 0) {
    pbuffer += n;
    maxlen -= n;
    len += n;

    buffer[len] = '\0';
    printf("%s",buffer);
  }

    printf("%s",buffer);  
    

   /* may need a loop here so it will take the next message? */ 
   
  close(aSocket);
  return 0;

}
