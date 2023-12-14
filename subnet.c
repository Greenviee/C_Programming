#include <stdio.h>
#include <string.h>

typedef struct {
	unsigned int first;
	unsigned int second;
	unsigned int third;
	unsigned int fourth;		
}Ip;

Ip getip(char* str) {
	int i = 0;
	Ip ret;
	ret.first = ret.second = ret.third = ret.fourth = 0;
	while (str[i] != '.') {
		ret.first = ret.first * 10 + str[i] - '0';
		i++;
	}
	i++;
	while (str[i] != '.') {
		ret.second = ret.second * 10 + str[i] - '0';
		i++;
	}
	i++;
	while (str[i] != '.') {
		ret.third = ret.third * 10 + str[i] - '0';
		i++;
	}
	i++;
	while (i < strlen(str)) {
		ret.fourth = ret.fourth * 10 + str[i] - '0';
		i++;
	}
	
	return ret;
}

Ip getNetwork(Ip a, Ip b) {
	Ip ret;
	ret.first = a.first & b.first;
	ret.second = a.second & b.second;
	ret.third = a.third & b.third;
	ret.fourth = a.fourth & b.fourth;
	return ret;
}

int bits(int a, int i) {
	if (i == 8) return 0;
	if ((a & (1 << i)) != 0)
		return 1 + bits(a, i+1);
	else
		return bits(a, i+1);
}

int main() {
	Ip address, subnet, network;
	char str[101];
	scanf("%s", str);
	address = getip(str);
	scanf("%s", str);
	subnet = getip(str);
	
	network = getNetwork(address, subnet);
	int answer = bits(network.first, 0);
	answer += bits(network.second, 0);
	answer += bits(network.third, 0);
	answer += bits(network.fourth, 0);
	
	printf("%d", answer);
}
