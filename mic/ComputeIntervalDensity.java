package com.mic;

import java.lang.reflect.Array;

public class ComputeIntervalDensity {
    //enter the chord here
    double[] _pitches = {0, 0.5, 1, 1.5, 2, 3};

    public ComputeIntervalDensity() {


        double[][] x = getIntervalDensity(_pitches);
        double[] y = prettyPrint(x, 6);
        printVector(y, 12);

    }

    double[][] getIntervalDensity(double[] pitchArray) {

        int length = Array.getLength(pitchArray);
        double[][] pitchMatrix = new double[length][length];

        for (int i = 0; i < length; i++) {

            for (int j = 0; j < length; j++) {

                pitchMatrix[i][j] = pitchArray[j] - pitchArray[i];

            }
        }
        System.out.println("Solution matrix:");
        printSqMatrix(pitchMatrix, 6);
        System.out.println("Vector:");


        return pitchMatrix;
    }

    void printSqMatrix(double[][] matrix, int n) {

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                System.out.print(matrix[i][j] + " ");

            }
            System.out.print("\n");
        }
    }


    void printVector(double[] matrix, int n) {
        System.out.print("< ");
        for (int i = 0; i < n; i++) {

            System.out.print((int)matrix[i] + " ");

        }

        System.out.print(">");
    }


    double[] prettyPrint(double[][] pitchMatrix, int n) {

        double[] pitchVector = new double[12];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {

                if (pitchMatrix[i][j] == 0.5) pitchVector[0]++;
                if (pitchMatrix[i][j] == 1.0) pitchVector[1]++;
                if (pitchMatrix[i][j] == 1.5) pitchVector[2]++;
                if (pitchMatrix[i][j] == 2.0) pitchVector[3]++;
                if (pitchMatrix[i][j] == 2.5) pitchVector[4]++;
                if (pitchMatrix[i][j] == 3.0) pitchVector[5]++;
                if (pitchMatrix[i][j] == 3.5) pitchVector[6]++;
                if (pitchMatrix[i][j] == 4.0) pitchVector[7]++;
                if (pitchMatrix[i][j] == 4.5) pitchVector[8]++;
                if (pitchMatrix[i][j] == 5.0) pitchVector[9]++;
                if (pitchMatrix[i][j] == 5.5) pitchVector[10]++;
                if (pitchMatrix[i][j] == 6.0) pitchVector[11]++;

            }
        return pitchVector;
    }

    public static void main(String[] args) {

        new ComputeIntervalDensity();

    }
}