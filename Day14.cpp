/* QUESTION: Given two numbers, hour and minutes. Return the smaller angle (in degrees) formed between the hour and the minute hand.

Example 1:

Input: hour = 12, minutes = 30
Output: 165
Example 2:

Input: hour = 3, minutes = 30
Output: 75
Example 3:

Input: hour = 3, minutes = 15
Output: 7.5
Example 4:

Input: hour = 4, minutes = 50
Output: 155
Example 5:

Input: hour = 12, minutes = 0
Output: 0
*/

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hourDegree = (hour+(minutes/60.00))*30.00; // Hour*30 for degrees hour needle has covered + extra degrees covered by hour according to minute.
        double minDegree = minutes*6.00; // 1 minute is 6 degrees
        
        double diff = abs(hourDegree - minDegree);
        
        return min(diff, 360.00-diff);
    }
};
