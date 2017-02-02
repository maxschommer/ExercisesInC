#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int card_values(char card_name[]) { 
	/*This function returns the value of the card based on the
	character entered */
	int val2 = 0;
	switch(card_name[0]) {
			case 'K':
			case 'Q':
			case 'J':
				val2 = 10;
				break;
			case 'A':
				val2 = 11;
				break;
			case 'X':
				return INT_MIN;
			default:
				val2 = atoi(card_name);
				if ((val2 < 1)||(val2>10)) {
					puts("I don't understand that value!");
					return INT_MAX;
				}
			}
	return val2;
}

int counter(int val3) {
	/*This returns the count increment based on 
	the value entered */
	int count2 = 0;
	if ((val3>2)&&(val3<7)) {
			count2 = 1;
		} else if (val3 == 10) {
			count2 = -1;
		}
	return count2;
}

int main() {
	/*This is the main function which 
	contains the loop that counts cards*/
	char card_name[3];
	int count = 0;
	int val4 = 0;

	while (card_name[0] != 'X') {
		puts("enter the card name: ");
		scanf("%2s", card_name);
		
		val4 = card_values(card_name);
		if (val4 == INT_MIN) {
			break;
		} else if (val4 == INT_MAX) {
			continue;
		}
		count += counter(val4);
		
		printf("Current count: %i\n", count);
	}
	return 0;
}