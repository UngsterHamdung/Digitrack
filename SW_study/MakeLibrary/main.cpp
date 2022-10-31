#pragma once
#include <iostream>
#include "Pokemon.h"
using namespace std;

int Pokemon::size()
{
	return len;
}

bool Pokemon::isempty()
{
	return len == 0;
}

void Pokemon::CreatePokemonDict()
{
	PokemonInfo* node = new PokemonInfo;
	AddPokemon(node);
}

void Pokemon::AddPokemon(PokemonInfo* node)
{
	char name[50];
	char type[50];
	int number;
	cout << "포켓몬의 이름을 적어주세용: ";
	cin >> name;
	cout << "포켓몬의 번호를 적어주세요: ";
	cin >> number;
	cout << "포켓몬의 타입을 적어주세요: ";
	cin >> type;
	node->number = number;
	strcpy_s(node->name, strlen(name) + 1, name);
	strcpy_s(node->type, strlen(name) + 1, type);
	node->next = NULL;

	if (isempty()) {
		front = rear = node;
	}
	else {
		rear->next = node;
		rear = rear->next;
	}
	len = len + 1;
	cout << endl;
}

PokemonInfo* Pokemon::SearchPokemon(char PokeName[])
{
	PokemonInfo* curNode = front;
	while (strcmp(curNode->name, PokeName))
	{
		curNode = curNode->next;
	}

	return curNode;
}

void Pokemon::RemovePokemon(char PokeName[]) {
	if (isempty())
	{
		cout << "Q is empty" << endl;
		return;
	}
	PokemonInfo* delNode = front;
	while (strcmp(delNode->name, PokeName))
	{
		delNode = delNode->next;
	}
	front = delNode->next;
	free(delNode);

	len = len - 1;
	cout << endl;

}

void Pokemon::ShowPokemon()
{
	PokemonInfo* curNode = front;

	while (!isempty())
	{
		cout << curNode->name << endl;
		cout << curNode->number << endl;
		cout << curNode->type << endl;
		curNode = curNode->next;
		len = len - 1;
		cout << endl;
	}

}
