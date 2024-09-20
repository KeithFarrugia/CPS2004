# Code Organization

## General Overview

Each Task has its own file where the code for that task is listed. Meaning The code for Task 4 is located in the Task 4 folder.

Each file then has subfolders Each subfolder dedicated to either the java implementation or the c++ implementation. Example Task 1 contains the folders C++ and Java which are the same implementation but different Languages. While Task 4 for example, Appart from the the folder holding the main java implementation, then has two further C++ folders; one for the gRPC server and the other for the stock viewer.

## Logistics Project Organization

The general Structure of the code is mostly the same. All files relating to either product, shipment or transport are located inside the Components folder or inside relating folders inside Components. Special Classes such as for Serialization or for gRPC are contained inside their own named folder in the same directory as Components.