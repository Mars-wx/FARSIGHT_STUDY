#!/bin/bash

TARNAME=myHome.tar.gz
TARPATH=/mnt/hgfs/share/

tar cvfz $TARNAME $HOME/*
cp $TARNAME $TARPATH

echo done
