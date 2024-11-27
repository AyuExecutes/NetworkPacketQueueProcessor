# Network Packet Queue Processor 

## Overview 
The Network Packet Queue Processor is a C++ program that simulates the processing of network packets in an input-output port system. It uses queues to handle incoming packets, transfer them to output queues, and display the results in a structured format.

## Features
- Processes packets based on their input and output ports.
- Ensures valid ports (0-255) and handles errors for invalid input/output ports.
- Supports both console input and file-based input.
- Outputs the results in a structured format for readability.

## Input Format
The input consists of multiple lines, where each line represents a cycle of packets. The format of each line is:  
`<number_of_packets> <input_port_1> <output_port_1> <value_1> <input_port_2> <output_port_2> <value_2>`

## Example Input
        4 2 1 one 2 1 two 3 4 three 4 5 four  
        2 1 6 five 1 6 six

### Output Format
The output consists of the processed packets, printed in the order they are processed. Each line represents the output port and the values of the packages in that port.  

        1 one two
        4 three
        5 four
        6 five six

### Explanation
- First line: **4 packets** are coming in the cycle.  
Packet 1: From input port 2 to output port 1, with value one.  
Packet 2: From input port 2 to output port 1, with value two.  
Packet 3: From input port 3 to output port 4, with value three.  
Packet 4: From input port 4 to output port 5, with value four.  

- Second line: **2 packets** are coming in the cycle.  
Packet 1: From input port 1 to output port 6, with value five.  
Packet 2: From input port 1 to output port 6, with value six.  

## Notes
- Valid port numbers are between 0 to 255.

## Usage Instructions
### Prerequisites
- A C++ compiler (e.g., g++).
- Command-line environment.

### Compilation
To compile the program run:  
`g++ -o NetworkPacketQueueProcessor NetworkPacketQueueProcessor.cpp`

### Running the Program
**Option 1**: Using Console Input  
Run the program and provide input. End the input by pressing `Ctrl+D` (Linux/Mac) or `Ctrl-Z` (Windows).  

#### Example session:  
        $ ./NetworkPacketQueueProcessor  
        3 5 8 hello 5 8 world 5 8 test  
        2 5 8 again 6 7 done  
        <Ctrl+D>

**Option 2**: Using Piped Input  
Use the `cat` command to pipe input from a file:  
` cat input.in | ./NetworkPacketQueueProcessor`

## Error Handling
The program gracefully handles:
- **Invalid Ports**: Prints an error for input/output ports outside the range (0-255).
- **Invalid Input Format**: Displays an error if the input line does not match the expected format.
- **Empty Input**: Simply exits without any output.




