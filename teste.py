#!/usr/bin/env pybricks-micropython
from pybricks.iodevices import UARTDevice
from pybricks.parameters import Port
from pybricks.tools import wait

uart = UARTDevice(Port.S1, baudrate=115200)
print("🔍 Aguardando dados da Serial...")

while True:
    if uart.waiting():
        data = uart.read_all()
        print("Recebido:", data)
    wait(500)
