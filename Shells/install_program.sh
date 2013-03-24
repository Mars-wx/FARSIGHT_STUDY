#!/bin/bash

sudo apt-get install vim
#the all package downloaded are under /var/cache/apt/archives/ 

sudo apt-get install ctags

mv /mnt/hgfs/share/vim.tar.gz ~

tar xvf vim.tar.gz

sudo mkdir /tftpboot

sudo chmod 777 /tftpboot/

sudo apt-get install tftp-hpa tftpd-hpa
#need config /etc/default/tftpd-hpa 
#	set TFTP_DIRECTORY="/tftpboot"
#	    TFTP_OPTIONS="--secure -c -l"

sudo /etc/init.d/tftpd-hpa restart

sudo mkdir /nfsroot

sudo chmod 777 /nfsroot/

sudo apt-get install nfs-kernel-server
#need config /etc/exports 
#	add one line: /nfsroot  *(rw,sync,no_subtree_check)
#sudo mount -t -nfs 127.1:/nfsroot nfs //the last nfs is the directory you
#				//create under the /home/username/ , it is the mount point

sudo /etc/init.d/nfs-kernel-server restart 
