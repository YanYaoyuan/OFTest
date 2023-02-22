#include "pcap_analysis.h"
#pragma comment (lib,"ws2_32.lib")
pcap_analysis::pcap_analysis()
{

}

/*下边是以太网的协议格式 */
struct ethernet_header
{
    u_int8_t ether_dhost[6];  /*目的以太地址*/
    u_int8_t ether_shost[6];  /*源以太网地址*/
    u_int16_t ether_type;      /*以太网类型*/
};

/*ip地址格式*/
typedef u_int32_t in_addr_t;

struct ip_header
{
#ifdef WORKS_BIGENDIAN
    u_int8_t ip_version:4,    /*version:4*/
    ip_header_length:4;       /*IP协议首部长度Header Length*/
#else
 u_int8_t ip_header_length:4,
       ip_version:4;
#endif
    u_int8_t ip_tos;               /*服务类型Differentiated Services  Field*/
    u_int16_t ip_length;           /*总长度Total Length*/
    u_int16_t ip_id;               /*标识identification*/
    u_int16_t ip_off;              /*片偏移*/
    u_int8_t ip_ttl;               /*生存时间Time To Live*/
    u_int8_t ip_protocol;          /*协议类型（TCP或者UDP协议）*/
    u_int16_t ip_checksum;         /*首部检验和*/
    struct in_addr  ip_source_address; /*源IP*/
    struct in_addr  ip_destination_address; /*目的IP*/
};


/*关于tcp头部的定义*/
struct tcp_header
{
    u_int16_t tcp_source_port;		  //源端口号

    u_int16_t tcp_destination_port;	//目的端口号

    u_int32_t tcp_acknowledgement;	//序号

    u_int32_t tcp_ack;	//确认号字段
#ifdef WORDS_BIGENDIAN
    u_int8_t tcp_offset:4 ,
    tcp_reserved:4;
#else
    u_int8_t tcp_reserved:4,
    tcp_offset:4;
#endif
    u_int8_t tcp_flags;
    u_int16_t tcp_windows;	//窗口字段
    u_int16_t tcp_checksum;	//检验和
    u_int16_t tcp_urgent_pointer;	//紧急指针字段
};


///*下边实现tcp数据包分析的函数定义tcp_protocol_packet_callback*/
//void pcap_analysis::tcp_protocol_packet_callback(u_char *argument,const struct pcap_pkthdr* packet_header,const u_char* packet_content)
//{
//    struct tcp_header *tcp_protocol ;     /*tcp协议变量*/
//    u_char flags;                          /*标记*/
//    int header_length;                  /*头长度*/
//    u_short source_port;           /*源端口*/
//    u_short destination_port;   /*目的端口*/
//    u_short windows;                /*窗口大小*/
//    u_short urgent_pointer;     /*紧急指针*/
//    u_int sequence;                 /*序列号*/
//    u_int acknowledgement;   /*确认号*/
//    u_int16_t   checksum;       /*检验和*/
//    tcp_protocol=(struct tcp_header *) (packet_content+14+20);  /*获得tcp首部内容*/
//    source_port =ntohs(tcp_protocol->tcp_source_port);                  /*获得源端口号*/
//    destination_port =ntohs(tcp_protocol->tcp_destination_port); /*获得目的端口号*/
//    header_length =tcp_protocol->tcp_offset *4;                            /*获得首部长度*/
//    sequence =ntohl(tcp_protocol->tcp_acknowledgement);        /*获得序列号*/
//    acknowledgement =ntohl(tcp_protocol->tcp_ack);
//    windows = ntohs(tcp_protocol->tcp_windows);
//    urgent_pointer = ntohs(tcp_protocol->tcp_urgent_pointer);
//    flags = tcp_protocol->tcp_flags;
//    checksum =ntohs (tcp_protocol->tcp_checksum);
//    printf("\n==========    运输层（TCP协议）    ==========\n");
//    printf("源端口：\t %d\n",source_port);
//    printf("目的端口：\t %d\n",destination_port);

//    int min= ( destination_port <source_port )? destination_port : source_port ;
//    std::cout<<"应用层协议是：\t";
//    switch (min)
//    {
//    case 80:printf(" http 用于万维网（WWW）服务的超文本传输协议（HTTP）");
//        break;

//    case 21:printf(" ftp 文件传输协议（FTP）");
//        break;

//    case 23:printf(" telnet Telnet 服务  ");
//        break;

//    case 25:printf(" smtp 简单邮件传输协议（SMTP）");
//        break;

//    case 110:printf(" pop3 邮局协议版本3 ");
//        break;
//    case 443:printf(" https 安全超文本传输协议（HTTP） ");
//        break;

//    default :printf("【其他类型】 ");
//        break;
//    }
//    std::cout<<std::endl;
//    printf("序列号：\t %u \n",sequence);
//    printf("确认号：\t%u \n",acknowledgement);
//    printf("首部长度：\t%d \n",header_length);
//    printf("保留字段：\t%d \n",tcp_protocol->tcp_reserved);
//    printf("控制位：");
//    if (flags & 0x08)  printf("\t【推送 PSH】");
//    if (flags & 0x10)  printf("\t【确认 ACK】 ");
//    if (flags & 0x02)  printf("\t【同步 SYN】");
//    if (flags & 0x20)  printf("\t【紧急 URG】");
//    if (flags & 0x01)  printf("\t【终止 FIN】");
//    if (flags & 0x04)  printf("\t【复位 RST】");

//    printf("\n");
//    printf("窗口大小 :\t%d \n",windows);
//    printf("检验和 :\t%d\n",checksum);
//    printf("紧急指针字段 :\t%d\n",urgent_pointer);
//}

///*下边实现IP数据包分析的函数定义ethernet_protocol_packet_callback*/
//void pcap_analysis::ip_protocol_packet_callback(u_char *argument,const struct pcap_pkthdr* packet_header,const u_char* packet_content)
//{
//  struct ip_header *ip_protocol;   /*ip协议变量*/
//  u_int  header_length;    /*长度*/
//  u_int  offset;                   /*片偏移*/
//  u_char  tos;                     /*服务类型*/
//  u_int16_t checksum;    /*首部检验和*/
//  ip_protocol=(struct ip_header*) (packet_content+14); /*获得ip数据包的内容去掉以太头部*/
//  checksum=ntohs(ip_protocol->ip_checksum);      /*获得校验和*/
//  header_length=ip_protocol->ip_header_length*4; /*获得长度*/
//  tos=ip_protocol->ip_tos;    /*获得tos*/
//  offset=ntohs(ip_protocol->ip_off);   /*获得偏移量*/
//  printf("\n##########    网络层（IP协议）    ########### \n");
//  printf("IP版本:\t\tIPv%d\n",ip_protocol->ip_version);
//  printf("IP协议首部长度:\t%d\n",header_length);
//  printf("服务类型:\t%d\n",tos);
//  printf("总长度:\t\t%d\n",ntohs(ip_protocol->ip_length));/*获得总长度*/
//  printf("标识:\t\t%d\n",ntohs(ip_protocol->ip_id));  /*获得标识*/
//  printf("片偏移:\t\t%d\n",(offset&0x1fff)*8);    /**/
//  printf("生存时间:\t%d\n",ip_protocol->ip_ttl);     /*获得ttl*/
//  printf("首部检验和:\t%d\n",checksum);
//  printf("源IP:\t%s\n",inet_ntoa(ip_protocol->ip_source_address));          /*获得源ip地址*/
//  printf("目的IP:\t%s\n",inet_ntoa(ip_protocol->ip_destination_address));/*获得目的ip地址*/
//  printf("协议号:\t%d\n",ip_protocol->ip_protocol);         /*获得协议类型*/
//  std::cout<<"\n传输层协议是:\t";
//  switch(ip_protocol->ip_protocol)
//  {
//  case 6 :
//      printf("TCP\n");
//      pcap_analysis::tcp_protocol_packet_callback(argument,packet_header,packet_content);
//      break; /*协议类型是6代表TCP*/
//  case 17:
//      printf("UDP\n");
//      break;/*17代表UDP*/
//  case 1:
//      printf("ICMP\n");
//      break;/*代表ICMP*/
//  case 2:
//      printf("IGMP\n");
//      break;/*代表IGMP*/
//  default :break;
//  }
//}

//pcap_handler ethernet_protocol_packet_callback()
//{
//    std::cout<<"ethernet_protocol_packet_callback 1"<<std::endl;
//    u_char *argument;
//    const struct pcap_pkthdr* packet_header;
//    const u_char* packet_content;
//    u_short ethernet_type;                                     /*以太网协议类型*/
//    struct ethernet_header *ethernet_protocol;  /*以太网协议变量*/
//    u_char *mac_string;
//    static int packet_number=1;
//    std::cout<<"ethernet_protocol_packet_callback 2"<<std::endl;
//    std::cout<<"*** ****** ******* *********   ********* ******* ****** ***"<<std::endl;
//    std::cout<<"\t!!!!!#    第【 "<<packet_number<<" 】个IP数据包被捕获    #!!!!!\n"<<std::endl;
//    std::cout<<"\n==========    链路层(以太网协议)    ==========\n"<<std::endl;
//    ethernet_protocol =(struct ethernet_header *) packet_content;  /*获得一太网协议数据内容*/
//    std::cout<<"以太网类型为 :\t"<<std::endl;
//    ethernet_type=ntohs(ethernet_protocol->ether_type); /*获得以太网类型*/
//    std::cout<<ethernet_type<<std::endl;

//    switch(ethernet_type)            /*判断以太网类型的值*/
//    {
//    case 0x0800 :
//        std::cout<<"网络层是：\tIPv4协议\n"<<std::endl;break;
//    case 0x0806 :
//        std::cout<<"网络层是：\tARP协议\n"<<std::endl;break;
//    case 0x8035 :
//        std::cout<<"网络层是：\tRARP 协议\n"<<std::endl;break;
//    default: break;
//    }
//    /*获得Mac源地址*/
//    std::cout<<"Mac源地址:\t"<<std::endl;
//    std::cout<<"ethernet_protocol_packet_callback 3"<<std::endl;
//    mac_string=ethernet_protocol->ether_shost;
//    qDebug("%02x:%02x:%02x:%02x:%02x:%02x:\n",*mac_string,*(mac_string+1),*(mac_string+2),*(mac_string+3),*(mac_string+4),*(mac_string+5));

//    std::cout<<*mac_string<<","<<*(mac_string+1)<<","<<*(mac_string+2)<<","<<*(mac_string+3)<<","<<*(mac_string+4)<<","<<*(mac_string+5)<<std::endl;

//    /*获得Mac目的地址*/
//    std::cout<<"Mac目的地址:\t"<<std::endl;
//    mac_string=ethernet_protocol->ether_dhost;
//    std::cout<<*mac_string<<","<<*(mac_string+1)<<","<<*(mac_string+2)<<","<<*(mac_string+3)<<","<<*(mac_string+4)<<","<<*(mac_string+5)<<std::endl;
//    switch (ethernet_type)
//    {
//    case 0x0800:
//        /*如果上层是IPv4ip协议,就调用分析ip协议的函数对ip包进行贩治*/
//        //pcap_analysis::ip_protocol_packet_callback(argument,packet_header,packet_content);
//        break;
//    default :break;
//    }
//    packet_number++;

//    return 0;

//}


void aaa()
{
    std::cout<<"1111"<<std::endl;
}

void pcap_analysis::aaa()
{



    pcap_if_t *alldevs;
    pcap_if_t *d;
    int inum=0;
    int i = 0;
    pcap_t *adhandle;
    char errbuf[PCAP_ERRBUF_SIZE];

    /* 获得网卡的列表 */
    if(pcap_findalldevs(&alldevs, errbuf) == -1)
    {
        qDebug() << errbuf;
    }

    /* 打印网卡信息 */
    for(d = alldevs; d; d = d->next)
    {
        qDebug() << ++i << d->name;
        if(d->description)
            qDebug() << d->description;
        else
            qDebug("(No description available)");
    }
    if(i == 0)
    {
        qDebug("No interfaces found! Make sure WinPcap is installed.");
    }
    pcap_freealldevs(alldevs);

    std::cout<<"input index "<<i<<std::endl;
    //scanf("%d", &inum);               //输入要选择打开的网卡号
    inum =2;
    if(inum < 1 || inum > i) //判断号的合法性
    {
        printf("\n网卡号超出范围.\n");
        /*释放设备列表 */
        pcap_freealldevs(alldevs);

    }


    /* 找到要选择的网卡结构 */
    for(d=alldevs, i=0; i< inum-1 ;d=d->next, i++);

    /* 打开选择的网卡 */
    if ( (adhandle= pcap_open_live(d->name, /* 设备名称*/
                    65536,   /* 最大值.*/
                    /*65536允许整个包在所有mac电脑上被捕获.*/
                    1,       /* 混杂模式*/

  /*
  混杂模式是指一台主机能够接受所有经过它的数据流，不论这个数据流的目的地址是不是它，它都会接受这个数据包。也就是说，混杂模式下，网卡会把所有的发往它的包全部都接收。在这种情况下，可以接收同一集线器局域网的所有数据。
  */
                    1000,     /* 读超时为1秒*/
                    errbuf   /* error buffer*/
                    ) ) == NULL)
    {
      fprintf(stderr,"\n无法打开适配器.\t %s 不被LibPcap支持\n");
      /* Free the device list */
      pcap_freealldevs(alldevs);

    }

    bpf_u_int32 g_ipaddress,g_mipmask;
    char ip[INET_ADDRSTRLEN],mask[INET_ADDRSTRLEN];
    if(inet_ntop(AF_INET,&g_ipaddress,ip,sizeof(ip)) == NULL)
        perror("inet_ntop error");
    else if(inet_ntop(AF_INET,&g_mipmask,mask,sizeof(mask)) == NULL)
        perror("inet_ntop error");
    printf("IP address: %s, Network Mask: %s\n",ip,mask);
    //　显示打开的网卡信息
    QString sur_mac = QString("IP address: %1\nNetwork Mask: %2\n")
            .arg(ip).arg(mask);



    /* 开始以回调的方式捕获包
      函数名称：int pcap_loop(pcap_t * p,int cnt, pcap_handler callback, uchar * user);
      函数功能：捕获数据包,不会响应pcap_open_live()函数设置的超时时间
      */
    int cnt = 1;
    //pcap_loop(adhandle,cnt, (pcap_handler)ethernet_protocol_packet_callback(), NULL);

    const u_char* packet_content;
    u_short ethernet_type;                                     /*以太网协议类型*/
    struct ethernet_header *ethernet_protocol;  /*以太网协议变量*/
    ethernet_protocol =(struct ethernet_header *) packet_content;  /*获得一太网协议数据内容*/
    printf("net type :\t");
    ethernet_type=ntohs(ethernet_protocol->ether_type); /*获得以太网类型*/
    printf("ethernet_type =====    %04x\n",ethernet_type);

    //std::cout<<ethernet_protocol->ether_type<<std::endl;

    int res;
    struct tm* ltime;
    char timestr[16];
    struct pcap_pkthdr* header;
    const u_char* pkt_data;
    time_t local_tv_sec;
    u_int netmask;
    char packet_filter[] = "src host 192.168.9.101 and port 8080"; //过滤器
    struct bpf_program fcode;


      /* 获取数据包 */
    if(false)
    {
        while ((res = pcap_next_ex(adhandle, &header, &pkt_data)) >= 0)
        {

            if (res == 0)
                /* 超时时间到 */
                continue;

            /* 将时间戳转换成可识别的格式 */
            local_tv_sec = header->ts.tv_sec;
            ltime = localtime(&local_tv_sec);
            strftime(timestr, sizeof timestr, "%H:%M:%S", ltime);

            printf("%s,%.6d len:%d\n", timestr, header->ts.tv_usec, header->len);

            /* 打印包 */
            int len = header->caplen + 1;
            for (i = 1; i < len; i++)
            {
                printf("%.2x ", pkt_data[i - 1]);
                if ((i % 16) == 0)
                    printf("\n");
            }
            printf("\n-----------------------------------------------------------------\n");


        }
        if (res == -1) {
            printf("Error reading the packets: %s\n", pcap_geterr(adhandle));
            //return -1;
        }

    }
}
