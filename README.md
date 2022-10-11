# RollingCodeMAC
Generate and Verify random MAC Address. This is a small part of a project that require two mobile devices to communicated with each other without being tracked.

## Problem
The project require two portable devices that continuously scan each other using Bluetooth. In order to do this, the MAC Address of both devices need to be exposed. Movements of devices can be monitored if the MAC Address is fixed. One of the solution is to create a dynamic, rolling, decodable MAC Address to communicate between two devices without exposing the location or identity of both devices.

## Idea
 - The MAC Address follows the format ```AA:BB:CC:DD:EE:FF```
 - Choose 1 group as device signature: ```AA```
 - Choose 2 groups as base groups: ```CC``` and ```EE```
 - Choose 2 groups as encoded group: ```BB``` and ```DD```
 - Last group is the key to encode/decode the MAC Address: ```FF```
 - If the encoded groups can be decoded by the key then the MAC Address is valid
 - The MAC Address changes ever 5 minutes

## Solution
There are two file: ```slave.py``` and ```master.py```
 - slave.py: Generate a dynamic MAC Address.
 - master.py: Verify if the provided MAC Address is valid. If yes, the other device with that MAC is the desire one.
