// You are given an array of CPU tasks, each labeled with a letter from A to Z, and a number n. Each CPU interval can be idle or allow the completion of one task. Tasks can be completed in any order, but there's a constraint: there has to be a gap of at least n intervals between two tasks with the same label.
// Return the minimum number of CPU intervals required to complete all tasks.
// Name: Vatsal Agarwal
// SAP ID: 590023223

#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int leastInterval(char *tasks, int tasksSize, int n)
{
    int freq[26] = {0};
    int maxFreq = 0;
    int maxFreqCount = 0;

    for (int i = 0; i < tasksSize; i++)
    {
        int index = tasks[i] - 'A';
        freq[index]++;
        if (freq[index] > maxFreq)
        {
            maxFreq = freq[index];
        }
    }
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] == maxFreq)
        {
            maxFreqCount++;
        }
    }

    int intervals = (maxFreq - 1) * (n + 1) + maxFreqCount;

    return MAX(intervals, tasksSize);
}