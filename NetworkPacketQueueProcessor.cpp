#include <iostream>
#include <queue>
#include <string>
#include <sstream>
using namespace std;

struct Package {
    int outputPort;
    string value;
};

// Function initialisation
void insertValues(queue<Package> (&inputQueue)[256], queue<Package> (&outputQueue)[256]);
void transferValues(queue<Package> (&inputQueue)[256], queue<Package> (&outputQueue)[256]);
void printResult(queue<Package> (&outputQueue)[256]);
void printOutputQueue(queue<Package> outputQueue);

int main(){
    queue<Package> inputQueue[256];
    queue<Package> outputQueue[256];
    insertValues(inputQueue, outputQueue);
    return 0;
}

// Function accepts packages for every cycle, processes them, and continues until the input queue is empty
void insertValues(queue<Package> (&inputQueue)[256], queue<Package> (&outputQueue)[256]){

    
    string line;                // Represents each line of input
    int totalPackages;          // Represents the first number on each line 
    int cycleCount = 0;         // Represents the cycle count

    while (true){
        if (!getline(cin, line)){
            // When there is no more line to read, increase the cycle count and process the data (input queue might not be empty)
            if (cin.fail()){
                cycleCount++;
                transferValues(inputQueue, outputQueue);

                // Check if the input queue is empty, if it is, print the result and break the loop
                bool queueIsEmpty = true;
                for (int i = 0; i < 256; i++){
                    if (!inputQueue[i].empty()){
                        queueIsEmpty = false;
                    }
                }

                if (queueIsEmpty){
                    printResult(outputQueue);
                    break;
                }
            }

        } else {

            // Whenever there is a line to read, cycle count will be increased
            cycleCount++;

            /* Using stringstream to process the line,
            pattern is: first number on each line is the total number of packages that are coming in the cycle,
            then, next 3 entity on each line will be the input port -> output port -> value.
            */
            stringstream stringstream(line);

            if (!(stringstream >> totalPackages)){
                cerr << "Error: Invalid input format for totalPackages" << endl;
                continue;
            }

            int inputPort, outputPort;
            string val;

            // Iterate through the total number of packages, get the values for each variable based on the pattern
            for (int i = 0; i < totalPackages; i++){

                if (!(stringstream >> inputPort >> outputPort >> val)){
                    cerr << "Error: Invalid input format for package" << endl;
                    continue;
                }
            
                Package package;
                package.outputPort = outputPort;
                package.value = val;

                // Check if the input port is within the range of 0 - 255, if it is, then push the package into the input queue
                if (inputPort >= 0 && inputPort <= 255){
                    inputQueue[inputPort].push(package);
                } else {
                    cerr << "Error: Invalid input port" << inputPort << endl;
                }
            }
            // After successfuly loading the input queue, data can be processed (cycle by cycle)
            transferValues(inputQueue, outputQueue);
        }
    }
}

// Function to process data, using access by reference to the queues
void transferValues(queue<Package> (&inputQueue)[256], queue<Package> (&outputQueue)[256]){

    // In ascending order, get the very front package, pop it, and transfer it to the output queue
    for (int i = 0; i <= 255; i++){
        if (!inputQueue[i].empty()){
            Package veryFront = inputQueue[i].front();
            inputQueue[i].pop();

            // Check for a valid output port, if it is, push the package into the output queue
            if (veryFront.outputPort >= 0 && veryFront.outputPort <= 255){
                outputQueue[veryFront.outputPort].push(veryFront);
            } else {
                cerr << "Error: Invalid output port" << veryFront.outputPort << endl;
            }
        }
    }
}

// Function to access the actual queue by reference, then printOutputQueue function will make a copy of the queue and print it
void printResult(queue<Package> (&queue)[256]){
    for (int i = 0; i <= 255; i++){
        if (!queue[i].empty()){
            printOutputQueue(queue[i]);
        }
    }

}

// Function to print the output queue, using pass by value since the actual queue should not be changed (this is only for printing purposes)
void printOutputQueue(queue<Package> queue){
    cout << queue.front().outputPort << " " ;
    while (!queue.empty()){
        cout << queue.front().value << " "; 
        queue.pop();
    }
    cout << endl;
}


