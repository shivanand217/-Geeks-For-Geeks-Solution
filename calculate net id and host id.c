#include<stdio.h>
#include<string.h>

char find_ip_class(char ip[]) {
    char f_octet[5];
    int i=0;
    int j=0;
    int len = strlen(ip);
    for(i=0; i < len; i++) {
        if(ip[i] == '.') {
            break;
        }
        f_octet[j++]=ip[i];
    }
    int ipnum = 0;
    j--;
    int p = 1;
    while( j >= 0 ) {
        ipnum = ipnum + (f_octet[j--] - '0')*p;
        p = p*10;
    }
    char ip_class;
    if(ipnum >= 1 && ipnum <= 126) {
        ip_class='A';
    }
    if(ipnum >= 128 && ipnum <= 191) {
        ip_class='B';
    }
    if(ipnum >= 192 && ipnum <= 223) {
        ip_class='C';
    }
    if(ipnum >= 224 && ipnum <= 239) {
        ip_class='D';
    }
    if(ipnum >= 240 && ipnum <= 255) {
        ip_class='E';
    }
    return ip_class;
}

void separate_ids(char ip[], char ip_class) {
    char netid[12],hostid[12];
    int i,j;
    printf("IP is %s\n" , ip);
    if(ip_class == 'A') {
        j=0;
        i=0;
        while(ip[i] != '.') {
            netid[j++] = ip[i++];
        }
        netid[j] = '\0';
        j=0;
        i++;
        while(i < strlen(ip)) {
            hostid[j++]=ip[i++];
        }
        hostid[j] = '\0';
        printf("Net Id is %s\n", netid);
        printf("Host Id is %s\n", hostid);
    }
    else if(ip_class == 'B') {
        i=0;
        j=0;
        int dotcount = 0;
        while( dotcount < 2 ) {
            if(ip[i] == '.')
                dotcount++;
            if(dotcount == 2){
                i++;break;
            }
            netid[j++]=ip[i++];
        }
        netid[j]='\0';
        j=0;
        while( i < strlen(ip) ){
            hostid[j++]=ip[i++];
        }
        hostid[j]='\0';
        printf("Net Id is %s\n",netid);
        printf("Host Id is %s\n",hostid);
    }
    else if(ip_class == 'C') {
        i=0;
        j=0;
        int dotcount=0;
        while(dotcount < 3){
            if(ip[i] == '.')
                dotcount++;
            if(dotcount == 3){
                i++;break;
            }
            netid[j++] = ip[i++];
        }
        netid[j]='\0';
        j=0;
        while( i < strlen(ip) ) {
            hostid[j++]=ip[i++];
        }
        hostid[j]='\0';
        printf("Net Id is %s\n",netid);
        printf("Host Id is %s\n",hostid);
    }
    else if(ip_class == 'D' || ip_class == 'E') {
        printf("ip addresses of class %c are not divided into network and host id parts\n" , ip_class);
    }
}

int main() {

    char ip1[] = "9.2.1.1";
    char ipclass = find_ip_class(ip1);
    printf("%c\n",ipclass);
    separate_ids(ip1, ipclass);
    putchar('\n');

    char ip2[] = "132.11.10.90";
    ipclass = find_ip_class(ip2);
    printf("%c\n",ipclass);
    separate_ids(ip2, ipclass);
    putchar('\n');

    char ip3[] = "196.11.10.90";
    ipclass = find_ip_class(ip3);
    printf("%c\n",ipclass);
    separate_ids(ip3, ipclass);
    putchar('\n');

    char ip4[] = "225.11.10.90";
    ipclass = find_ip_class(ip4);
    printf("%c\n",ipclass);
    separate_ids(ip4, ipclass);
    putchar('\n');

    return 0;
}
