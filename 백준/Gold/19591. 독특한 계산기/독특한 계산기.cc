#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void) {
	string expression;
	cin >> expression;
	stack <long long> front, rear;
	long long temp, digit, front_result, rear_result;
	int front_org_ptr, rear_org_ptr;
	char front_operator, rear_operator;
	int front_ptr = 0;
	int rear_ptr = expression.size() - 1;
	if (expression[0] == '-') {
		front_ptr++;
		temp = expression[front_ptr++] - '0';
		while ('0' <= expression[front_ptr] && expression[front_ptr] <= '9') {
			temp *= 10;
			temp += expression[front_ptr++] - '0';
		}
		temp *= -1;
		front.push(temp);
	}
	else {
		temp = expression[front_ptr++] - '0';
		while ('0' <= expression[front_ptr] && expression[front_ptr] <= '9') {
			temp = temp * 10;
			temp += expression[front_ptr++] - '0';
		}
		front.push(temp);
	}
	if (front_ptr > rear_ptr) {
		cout << front.top();
		return 0;
	}
	temp = 0;
	digit = 1;
	while ('0' <= expression[rear_ptr] && expression[rear_ptr] <= '9') {
		temp += digit * (expression[rear_ptr--] - '0');
		digit *= 10;
	}
	rear.push(temp);
	while (front_ptr < rear_ptr) {
		front_org_ptr = front_ptr;
		rear_org_ptr = rear_ptr;
		front_operator = expression[front_ptr++];
		temp = expression[front_ptr++] - '0';
		while ('0' <= expression[front_ptr] && expression[front_ptr] <= '9') {
			temp = temp * 10;
			temp += expression[front_ptr++] - '0';
		}
		switch (front_operator) {
		case '+': front_result = front.top() + temp; break;
		case '-': front_result = front.top() - temp; break;
		case '*': front_result = front.top() * temp; break;
		case '/': front_result = front.top() / temp; break;
		}
		rear_operator = expression[rear_ptr--];
		temp = 0;
		digit = 1;
		while ('0' <= expression[rear_ptr] && expression[rear_ptr] <= '9') {
			temp += digit * (expression[rear_ptr--] - '0');
			digit *= 10;
		}
		switch (rear_operator) {
		case '+': rear_result = temp + rear.top(); break;
		case '-': rear_result = temp - rear.top(); break;
		case '*': rear_result = temp * rear.top(); break;
		case '/': rear_result = temp / rear.top(); break;
		}		
		if ((front_operator == '*' || front_operator == '/') && (rear_operator == '+' || rear_operator == '-')) {
			rear_ptr = rear_org_ptr;			
			front.pop();
			front.push(front_result);
		}
		else if ((rear_operator == '*' || rear_operator == '/') && (front_operator == '+' || front_operator == '-')) {
			front_ptr = front_org_ptr;
			rear.pop();
			rear.push(rear_result);
		}
		else if (front_result >= rear_result) {
			rear_ptr = rear_org_ptr;
			front.pop();
			front.push(front_result);
		}
		else {
			front_ptr = front_org_ptr;
			rear.pop();
			rear.push(rear_result);
		}
	}
	if (front_ptr == rear_ptr) {		
		switch (expression[front_ptr]) {
		case '+': cout << front.top() + rear.top(); return 0;
		case '-' : cout << front.top() - rear.top(); return 0;
		case '*' : cout << front.top() * rear.top(); return 0;
		case '/' : cout << front.top() / rear.top(); return 0;
		}
	}
	return 0;
}