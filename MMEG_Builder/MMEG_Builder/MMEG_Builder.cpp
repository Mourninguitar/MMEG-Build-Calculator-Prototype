#include "pch.h"
#include <iostream>
#include "MMEG_Builder.h"
#include <string>

using namespace std;

// WHAT AM I?: I am a Build Reccomendation bot for MMEG, 
// You tell me the mechanics of your monster's skills, and I'll reccomend a rough build for you to maximise your monster's damage output



int main()
{
	Stats MyStats;
	Skill Skill1, Skill2, Skill3;
	Wave ThisWave;
	Monster MyMonster;


	// Print intro text


	// Get Input Data
	cout << "How many enemies in this wave?: ";
	cin >> ThisWave.EnemyCount;
	cout << endl;
	EnterInputs(MyMonster, MyStats, Skill1, Skill2, Skill3);


	// Calculate best build
	


	// Output
	PrintStats(MyStats);
	cout << CalculateSkillDamage(MyMonster.MonsterSkill1, MyMonster.MonsterStats);
	cout << CalculateSkillDamage(MyMonster.MonsterSkill2, MyMonster.MonsterStats);
	cout << CalculateSkillDamage(MyMonster.MonsterSkill3, MyMonster.MonsterStats);

	return 0;
}

void EnterInputs(Monster MyMonster, Stats &MyStats, Skill &Skill1, Skill &Skill2, Skill &Skill3)
{
	InputStats(MyMonster, MyStats);
	cout << endl;

	EnterSkillMechanics(MyMonster, Skill1, "1");
	cout << endl;

	EnterSkillMechanics(MyMonster, Skill2, "2");
	cout << endl;

	EnterSkillMechanics(MyMonster, Skill3, "3");
	cout << endl;
}

float CalculateSkillDamage(Skill s, Stats m)
{
	int ATK = m.Attack;
	int HP = m.HitPoints;
	int DEF = m.Defense;
	int SPD = m.Speed;
	float CC = m.CritChance;
	float CD = m.CritDamage;
	float ACC = m.Accuracy;
	float RES = m.Resistance;
	
	float SkillUp = s.SkillupMultiplier;
	float HPScaling = s.HPScaling;
	float ATKScaling = s.ATKScaling;
	float SPDScaling = s.SPDScaling;
	float DEFScaling = s.DEFScaling;
	float CDScaling = s.CritDMGScaling;

	float BaseDamage = (ATK * ATKScaling) + (HP * HPScaling) + (DEF * DEFScaling) + (SPD * SPDScaling) + (CD * CDScaling);
	float AverageDamage = SkillUp * BaseDamage + (CC * (BaseDamage * CD));
	float NormalHitDamage = SkillUp * BaseDamage;
	float CriticalHitDamage = SkillUp * BaseDamage + (BaseDamage * CD);

	float Output[3] = { AverageDamage, NormalHitDamage, CriticalHitDamage };

	return AverageDamage;
}

void EnterSkillMechanics(Monster MyMonster, Skill &ThisSkill, string SkillNumber)
{
	ThisSkill.Passive = bInput("Passive");
	ThisSkill.AOE = bInput("AOE");
	ThisSkill.Cooldown = iInput("Skill Cooldown");
	ThisSkill.CritChanceBonus = fInput("Bonus crit chance");

	ThisSkill.SkillupMultiplier = fInput("Skill up multiplier");
	ThisSkill.ATKScaling = fInput("Attack scaling multiplier");
	ThisSkill.HPScaling = fInput("HP scaling multiplier");
	ThisSkill.DEFScaling = fInput("DEF scaling multiplier");
	ThisSkill.SPDScaling = fInput("SPD scaling multiplier");
	ThisSkill.CritDMGScaling = fInput("Crit Damage scaling multiplier");

	cout << endl;

	if (SkillNumber == "1") {
		MyMonster.MonsterSkill1 = ThisSkill;
		return;
	}
	else if (SkillNumber == "2") {
		MyMonster.MonsterSkill2 = ThisSkill;
		return;
	}
	else if (SkillNumber == "3") {
		MyMonster.MonsterSkill3 = ThisSkill;
		return;
	}

	cout << "ERROR: SKILL NUMBER IS NOT VALID";
	return;
}

void InputStats(Monster MyMonster, Stats &MyStats)
{
	MyStats.HitPoints = iInput("HP");
	MyStats.Attack = iInput("Attack");
	MyStats.Defense = iInput("Defense");
	MyStats.Speed = iInput("Speed");
	MyStats.CritChance = fInput("Critical Chance");
	MyStats.CritDamage = fInput("Critical Damage");
	MyStats.Accuracy = fInput("Accuracy");
	MyStats.Resistance = fInput("Resistance");
	
	MyMonster.MonsterStats = MyStats;
	cout << endl;
}

void PrintStats(Stats &MyStats)
{
	cout << endl;
	cout << "HP : " << MyStats.HitPoints << endl;
	cout << "ATK: " << MyStats.Attack << endl;
	cout << "DEF: " << MyStats.Defense << endl;
	cout << "SPD: " << MyStats.Speed << endl;
	cout << "CC : " << MyStats.CritChance << endl;
	cout << "CD : " << MyStats.CritDamage << endl;
	cout << "ACC: " << MyStats.Accuracy << endl;
	cout << "RES: " << MyStats.Resistance << endl;
	
	cout << endl;
}