import java.io.*;
import java.util.*;

class MemoryBlock {
    int[] memory = new int[] { 100, 300, 40, 50, 150, 240, 200, 400};
    boolean[] free = new boolean[] { false, true, false, true, false, true, false, true };
    int[] processNumber = new int[] { 1, 2, 3, 4 };
    int divs = memory.length;
    int processSize;
    Scanner s = new Scanner(System.in);
    
    void processInput() {
        System.out.println("\n\tCurrent Scenario of the Memory Allocation \n");
        printTable(-1);
        System.out.print("\nEnter the size of the process that needs to be added (in KB): ");
        processSize = s.nextInt();
        choice();
    }
    
    void choice() {  
        bestFit();
    }

    void bestFit() {
        int ans = -1, curr = 1000000;
        for(int i = 0; i < divs; i++) {
            if(free[i] && processSize <= memory[i]) {
                if(memory[i] - processSize < curr) {
                    curr = memory[i] - processSize;
                    ans = i;
                }
            }
        }
        printTable(ans);
    }

    void printTable(int pos) {
        System.out.print("+----------------------------------------------------------+\n");
        System.out.print("|\tNo.\tMemory \t\t Status \t Process   |\n");
        System.out.print("+----------------------------------------------------------+\n");
        int j = 1, ok = 0;
        for (int i = 0; i < divs; i++) {
            if(i == pos) {
                System.out.print("|\t" + (i + 1) + " \t " +  processSize + "  \t\t " + " NF \t\t " + "Process " + (processNumber.length + 1) + " |");
                if(memory[i] - processSize != 0) {
                    System.out.print("\n|\t" + (i + 2) + " \t " + (memory[i] - processSize) + "  \t\t " + " F \t\t\t   |");
                    ok = 1;
                }
            }
            else {
                System.out.print("|\t" + (i + 1 + ok) + " \t " +  memory[i] + "  \t\t  " + ((free[i]) ? "F \t\t\t   |" : "NF \t\t " + "Process " + j++ + " |"));
            }
            System.out.println(' ');
        }
        System.out.print("+----------------------------------------------------------+\n");
    }
}

class BestFit {
    public static void main(String args[]) throws IOException
    {
        MemoryBlock m = new MemoryBlock();
        m.processInput();
    }
}