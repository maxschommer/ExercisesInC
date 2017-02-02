#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int card_values(char card_name[]) { 
	/*This function returns the value of the card based on the
	character entered */
	int val = 0;
	switch(card_name[0]) {
			case 'K':
			case 'Q':
			case 'J':
				val = 10;
				break;
			case 'A':
				val = 11;
				break;
			case 'X':
				return INT_MIN;
			default:
				val = atoi(card_name);
				if ((val < 1)||(val>10)) {
					puts("I don't understand that value!");
					return INT_MAX;
				}
			}
	return val;
}

int counter(int val) {
	/*This returns the count increment based on 
	the value entered */
	int count = 0;
	if ((val>2)&&(val<7)) {
			count = 1;
		} else if (val == 10) {
			count = -1;
		}
	return count;
}

int main() {
	/*This is the main function which 
	contains the loop that counts cards*/
	char card_name[3];
	int count = 0;
	int val = 0;
	

	while (card_name[0] != 'X') {
		puts("enter the card name: ");
		scanf("%2s", card_name);
		int val = 0;
		val = card_values(card_name);
		if (val == INT_MIN) {
			break;
		} else if (val == INT_MAX) {
			continue;
		}
		count += counter(val);
		
		printf("Current count: %i\n", count);
	}
	return 0;
}