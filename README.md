## RGB Coffeetable controller

This the the firmware for my 7x10 RGB coffetable. It is based on the ethersex embedded framework and
uses an ATMega32 on a Pollin Netio as hardware base.

Data is send to the controller using the artnet protocol. The pixels are controlled via 7x parallel SPI (bitbang).
