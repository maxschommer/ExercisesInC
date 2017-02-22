#ifndef TROUT_H
#define TROUT_H

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <time.h>
#include <netinet/in.h>
#include <netinet/in_systm.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <netinet/udp.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <sys/un.h>
#include <stdarg.h>
#include <syslog.h>
#include "util.h"

#define MAXLINE 4096
#define BUFSIZE 1500

int max_ttl;
int datalen;         /* length of the data in a datagram */
Sockaddr *sasend;    /* socket addresses for various purposes */
Sockaddr *sarecv;
Sockaddr *salast;
Sockaddr *sabind;
socklen_t salen;                    /* length of a socket address */

/* variables we might want to configure */

int nprobes;

int seq;

char recvbuf[BUFSIZE];
char sendbuf[BUFSIZE];
Rec *rec;

int sendfd, recvfd;
int pipefd[2];              /* the pipe for the alarm handler */

u_short sport;                      /* source UDP port # */
u_short dport;        /* destination port -- hopefully unused */
                                    /* 668 = the neighbor of the beast */
Timeval sendtv[1];
Timeval recvtv[1];
Timeval difftv[1];

/* NOTES: system calls beginning with a capital letter are Stevens's
   wrapper functions.  Each one invokes the method and checks the
   return value.  If the call fails, it invokes err_sys, which prints
   the error message and quits.

   Types that begin with a capital letter are usually typedefs
   that I added because (1) I hate seeing the word struct all over
   the place, and (2) it lets me pretend I am writing Java. */

/* sig_alrm: alarm handler sends a message to the process through
   a pipe, causing select to return */


void sig_alrm (int signo);
int process_ip (struct ip *ip, int len);
int recv_dgram ();
void sub_tv (Timeval *plus, Timeval *minus, Timeval *res);
double time_to_double (Timeval *time);
void print_report ();
void send_dgram (int ttl);
int send_probes (int ttl);
void loop_ttl ();

#endif