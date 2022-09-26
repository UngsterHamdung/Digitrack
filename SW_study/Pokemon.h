#pragma once

#ifdef DYNAMIC_EXPORTS
#	define DYNAMIC_DECLSPEC __declspec(dllexport)
#else
#	define DYNAMIC_DECLSPEC __declspec(dllimport)
#endif
struct PokemonInfo {
	int number;
	char name[50];
	char type[50];
	PokemonInfo* next;
};

class Pokemon {
	PokemonInfo* front, * rear;
	int len = 0;
public:
	Pokemon() {
		front = rear = NULL;
	}
	int size();
	bool isempty();
	void CreatePokemonDict();
	void AddPokemon(PokemonInfo* node);
	PokemonInfo* SearchPokemon(char PokeName[]);
	void RemovePokemon(char PokeName[]);
	void ShowPokemon();
};
