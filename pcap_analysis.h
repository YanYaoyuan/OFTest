#ifndef PCAP_ANALYSIS_H
#define PCAP_ANALYSIS_H
#include <iostream>
#include <Qtcore/QDebug>
#include "pcap.h"
class pcap_analysis
{
public:
    pcap_analysis();
    void aaa();

    void tcp_protocol_packet_callback(u_char *argument,const struct pcap_pkthdr* packet_header,const u_char* packet_content);
    void ip_protocol_packet_callback(u_char *argument,const struct pcap_pkthdr* packet_header,const u_char* packet_content);
    //void ethernet_protocol_packet_callback(u_char *argument,const struct pcap_pkthdr* packet_header,const u_char* packet_content);

    //void test();
};

#endif // PCAP_ANALYSIS_H
