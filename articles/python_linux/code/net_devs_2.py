#!/usr/bin/env python
from __future__ import print_function
from collections import namedtuple
import argparse

def netdevs(iface=None):
    ''' RX and TX bytes for each of the network devices '''

    with open('/proc/net/dev') as f:
        net_dump = f.readlines()
    
    device_data={}
    data = namedtuple('data',['rx','tx'])
    for line in net_dump[2:]:
        line = line.split(':')
        if not iface:
            if line[0].strip() != 'lo':
                device_data[line[0].strip()] = data(float(line[1].split()[0])/(1024.0*1024.0), 
                                                    float(line[1].split()[8])/(1024.0*1024.0))
        else:
            if line[0].strip() == iface:
                device_data[line[0].strip()] = data(float(line[1].split()[0])/(1024.0*1024.0), 
                                                    float(line[1].split()[8])/(1024.0*1024.0))    
    return device_data

if __name__=='__main__':

    parser = argparse.ArgumentParser(description='Network Interface Usage Monitor')
    parser.add_argument('-i','--interface', dest='iface',
                        help='Network interface')

    args = parser.parse_args()

    netdevs = netdevs(iface = args.iface)
    for dev in netdevs.keys():
        print('{0}: {1} MiB {2} MiB'.format(dev, netdevs[dev].rx, netdevs[dev].tx))
