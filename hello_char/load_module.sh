#!/bin/bash

module="hello_char"
device="hello_char"
mode="666"
group="root"

function load() {
    /sbin/insmod ./$module.ko $* || exit 1

    rm -f /dev/${device}0

    major=$(awk -v device="$device" '$2==device {print $1}' /proc/devices)
    mknod /dev/${device}0 c $major 0

    chgrp $group /dev/${device}0
    chmod $mode /dev/${device}0
}

function unload() {
    rm -f /dev/${device}0
    rmmod $module || exit 1
}

arg=${1:-"load"}

case $arg in
    load)
        load ;;
    unload)
        unload ;;
    reload)
        ( unload )
        load
        ;;
    *)
        echo "Usage: $0 {load | unload | reload}"
        echo "Default is load"
        exit 1
        ;;
esac

