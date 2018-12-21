#pragma once
#include "pch.h"
#include <iostream>
#include "MMEG_Builder.h"
#include <string>

using namespace std;

struct Wave {
	int EnemyCount = 0;
};
struct Stats
{
	int HitPoints = 0;
	int Attack = 0;
	int Defense = 0;
	int Speed = 0;
	float CritChance = 0;
	float CritDamage = 0;
	float Accuracy = 0;
	float Resistance = 0;
};
struct Skill
{
	bool Passive = false;
	bool AOE = false;

	float SkillupMultiplier = 1;
	float ATKScaling = 1;
	float HPScaling = 0;
	float DEFScaling = 0;
	float SPDScaling = 0;
	float CritDMGScaling = 0;

	int Cooldown = 1;
	float CritChanceBonus = 0;


};
struct Monster {
	Stats MonsterStats;
	Skill MonsterSkill1;
	Skill MonsterSkill2;
	Skill MonsterSkill3;
};

struct MaxedGlyphStats {
	float HP_Percent = 0.59;
	int HP_Flat = 3577;
	float ATK_Percent = 0.49;
	int ATK_Flat = 630;
	float DEF_Percent = 0.49;
	int DEF_Flat = 265;
	int Speed = 27;
	float CritChance = 0.23;
	float CritDamage = 0.66;
	float Accuracy = 0.23;
	float Resistance = 0.23;
};

struct HexGlyph {
	float MainStat = 0;
};
struct SquareGlyph {
	float MainStat = 0;
};
struct TearGlyph {
	float MainStat = 0;
};

struct Build {
	HexGlyph Hex_1;
	HexGlyph Hex_2;
	SquareGlyph Sqr_1;
	SquareGlyph Sqr_2;
	TearGlyph Tear_1;
	TearGlyph Tear_2;
};
Build Builds[20];


int iInput(string stat) {
	int intInput = 0;

	cout << "Please Enter " << stat << ": ";

	cin >> intInput;

	return intInput;
}
float fInput(string stat) {
	float floInput = 0;

	cout << "Please Enter " << stat << ": ";
	cin >> floInput;

	return floInput;
}
bool bInput(string stat) {

	bool boolInput = false;
	string Input = "";

	cout << "Is Skill " << stat << "?: ";
	cin >> Input;

	if (Input == "Y" || Input == "y") {
		boolInput = true;
	}
	else {
		boolInput = false;
	}

	return boolInput;
}

float CalculateSkillDamage(Skill s, Stats m);

void InputStats(Monster MyMonster, Stats &MyStats);
void PrintStats(Stats &MyMonster);
void EnterSkillMechanics(Monster MyMonster, Skill &ThisSkill, string SkillNumber);

void EnterInputs(Monster MyMonster, Stats &MyStats, Skill &Skill1, Skill &Skill2, Skill &Skill3);