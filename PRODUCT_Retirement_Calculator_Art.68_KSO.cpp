// PRODUCT_Retirement_Calculator_Art.68_KSO.cpp : Defines the entry point for the console application.
//
//Чл. 68. КСО - КОДЕКС ЗА СОЦИАЛНО ОСИГУРЯВАНЕ 
//01.01.2016  - 60 години и 10 месеца от жените и      (730 meseca)
//              63 години и 10 месеца от мъжете и      (766 meseca)
//осигурителен стаж 35 години и 2 месеца за жените и   (422 meseca)
//                  38 години и 2 месеца за мъжете     (458 meseca)

//От 31 декември 2016 г. възрастта се увеличава от първия ден на всяка следваща календарна година:
//1. до 31 декември 2029 г. възрастта за жените се увеличава с по 2 месеца за всяка календарна година, а
//от 1 януари 2030 г. - с по 3 месеца за всяка календарна година до достигане на 65-годишна възраст;  (780 months)

//2. до 31 декември 2017 г.възрастта за мъжете се увеличава с 2 месеца, а
//от 1 януари 2018 г. - с по 1 месец за всяка календарна година до достигане на 65 - годишна възраст. (780 months)

//(2) От 31 декември 2016 г.
//осигурителният стаж по ал. 1 се увеличава от първия ден на всяка следваща календарна година с по 2 месеца до
//достигане на осигурителен стаж 37 години за жените (444 months) и 40 години за мъжете (480 months). 

//(3) В случай че лицата нямат право на пенсия по ал. 1 и 2, 
//до 31 декември 2016 г.те придобиват право на пенсия 
//при навършване на възраст 65 години и 10 месеца за жените и мъжете и   (790 months)
//най - малко 15 години действителен осигурителен стаж.                  (180 months)
//От 31 декември 2016 г.възрастта се увеличава от първия ден на всяка следваща календарна година с
//по 2 месеца до достигане на 67 - годишна възраст.                            (804 months)
//(4) След 31 декември 2037 г.възрастта по ал. 1 се обвързва с нарастването на средната продължителност на живота.


#include "stdafx.h"
#include<iostream>
#include <string>
#include <cstdio>

//using namespace std;

int main()
{
	std::cout << "1 - female\n2 - male\n0 - Exit\nENTER genrer: ";
	unsigned short int gender;
	std::cin >> gender;
	std::cin.ignore();

	unsigned int ok_female_pension_age = 734;  //months 2018;  +2/y up 2029; +3   up 780 months
	unsigned int ok_male_pension_age = 769;  //months 2018;    + 1/y              up 780 months
	unsigned int ok_female_pension_Years_Work = 426;  //months 2018;  +2/y        up 444 months
	unsigned int ok_male_pension_Years_Work = 462;  //months 2018;    +2/y        up 480 months
	unsigned int ok_female_AND_male_pension_age_art_68_3 = 794;//months 2018;  +2/y up 804 months + 180 months WORK!
	unsigned int ok_female_AND_male_Years_Work_art_68_3 = 180;
	unsigned int top_65years_age = 780; // 65 - годишна възраст (780 months)
	unsigned int top_work_female_37yars = 444; //достигане на осигурителен стаж 37 години за жените (444 months) 
	unsigned int top_work_male_40yars = 480;  //достигане на осигурителен стаж 40 години за мъжете (480 months)
	unsigned int top_67female_AND_male_pension_age_art_68_3 = 804; // 67 - годишна възраст (804 months)

	while (gender) {
		switch (gender)
		{
		case 1:
		{
			//WOMEN
			std::cout << "How old are you THIS year? (NOTE:Current year you are/will be at age): ";
			unsigned short int age;
			std::cin >> age;
			age *= 12;
			std::cin.ignore();
			std::cout << "How many years have you been working till now? (NOTE:Real Insurance Years till NOW!): ";
			unsigned short int insuranceYears;
			std::cin >> insuranceYears;
			insuranceYears *= 12;
			std::cin.ignore();
			std::cout << "What year is now? (2018 or other): ";
			unsigned int year;
			std::cin >> year;
			std::cin.ignore();
			bool retired = false;
			unsigned int age_to_retire_Art_68_3 = age;
			unsigned int year_to_retire_Art_68_3 = year;
			unsigned int years_left_to_work_Art_68_3 = 180 - insuranceYears;
			const unsigned int start_years_left_to_work_Art_68_3 = years_left_to_work_Art_68_3;
			std::cout << "\n************************* YOUR RESULTS ***************************" << std::endl;
			while (age < ok_female_pension_age || insuranceYears < ok_female_pension_Years_Work)
			{
				if (age >= ok_female_pension_age && insuranceYears >= ok_female_pension_Years_Work)
				{
					break;
				}
				year++;
				age += 12;
				if (age >= 216)   //18 years old
				{
					insuranceYears += 12;
				}

				if (years_left_to_work_Art_68_3 >= 12 && age >= 216) {
					years_left_to_work_Art_68_3 -= 12;
				}
				else if (age >= 216)
				{
					years_left_to_work_Art_68_3 = 0;
				}

				if (ok_female_AND_male_pension_age_art_68_3 < top_67female_AND_male_pension_age_art_68_3 - 2)
				{
					ok_female_AND_male_pension_age_art_68_3 += 2;
				}
				if (age >= ok_female_AND_male_pension_age_art_68_3 &&
					insuranceYears >= ok_female_AND_male_Years_Work_art_68_3 &&
					retired == false)
				{
					//std::cout << "year: " << year << ": You CAN RETIRE under art.68_3 at age: " << age / 12 << std::endl;
					retired = true;
					age_to_retire_Art_68_3 = age;
					year_to_retire_Art_68_3 = year;
				}

				if (year < 2030 && ok_female_pension_age < top_65years_age - 2)
				{
					ok_female_pension_age += 2;
				}

				if (year >= 2030 && ok_female_pension_age < top_65years_age - 2)
				{
					ok_female_pension_age += 3;
				}

				if (ok_female_pension_Years_Work < top_work_female_37yars - 2)
				{
					ok_female_pension_Years_Work += 2;
				}
				//std::cout << "Your AGE: " << age / 12 << "; " << "years WORK: " << insuranceYears / 12 << ";" << std::endl;
			}

			if (age / 12 > 65)
			{
				printf("In year %d you will be %d years old, will have %d years work, and at last The LAW will allow you to retire. CONGRETS!!\n",
					year, age / 12, insuranceYears / 12);
				std::cout << "BUT..." << std::endl;

				if (start_years_left_to_work_Art_68_3 > 0) {
					printf("If you would like to retire earlier, you can DO IT in year %d, on %d! But you still have %d years left to reach the requirement of minimum 15 working years...\nWill have the lowest pension, sorry.\n\n",
						year_to_retire_Art_68_3, age_to_retire_Art_68_3 / 12, start_years_left_to_work_Art_68_3 / 12);
				}
				else
				{
					printf("If you would like to retire earlier, you can DO IT in year %d, on %d years age! \nWill have the lowest pension, sorry.\n",
						year_to_retire_Art_68_3, age_to_retire_Art_68_3 / 12);
				}
			}
			else
			{
				printf("In year %d you will be %d years old, will have %d years work, and at last The LAW will allow you to retire. CONGRETS!!\n",
					year, age / 12, insuranceYears / 12);
			}
			//CHECK
			//cout << "Gender: " << gender << ";" << " Age: " << age << ";" << " Insurance Years: " << insuranceYears << ";" << endl;
			std::cout << "******************************************************************" << std::endl;
			break;
		}
		case 2:
		{
			//MEN
			std::cout << "How old are you THIS year? (NOTE:Current year you are/will be at age): ";
			unsigned short int age;
			std::cin >> age;
			age *= 12;
			std::cin.ignore();
			std::cout << "How many years have you been working till now? (NOTE:Real Insurance Years till NOW!): ";
			unsigned short int insuranceYears;
			std::cin >> insuranceYears;
			insuranceYears *= 12;
			std::cin.ignore();
			std::cout << "What year is now? (2018 or other): ";
			unsigned int year;
			std::cin >> year;
			std::cin.ignore();
			bool retired = false;
			unsigned int age_to_retire_Art_68_3 = age;
			unsigned int year_to_retire_Art_68_3 = year;
			unsigned int years_left_to_work_Art_68_3 = 180 - insuranceYears;
			const unsigned int start_years_left_to_work_Art_68_3 = years_left_to_work_Art_68_3;
			std::cout << "\n************************* YOUR RESULTS ***************************" << std::endl;
			while (age < ok_male_pension_age || insuranceYears < ok_male_pension_Years_Work)
			{
				if (age >= ok_male_pension_age && insuranceYears >= ok_male_pension_Years_Work)
				{
					break;
				}
				year++;
				age += 12;
				if (age >= 216)   //18 years old
				{
					insuranceYears += 12;
				}
				if (years_left_to_work_Art_68_3 >= 12 && age >= 216) {
					years_left_to_work_Art_68_3 -= 12;
				}
				else if (age >= 216)
				{
					years_left_to_work_Art_68_3 = 0;
				}

				if (ok_female_AND_male_pension_age_art_68_3 < top_67female_AND_male_pension_age_art_68_3 - 2)
				{
					ok_female_AND_male_pension_age_art_68_3 += 2;
				}
				if (age >= ok_female_AND_male_pension_age_art_68_3 &&
					insuranceYears >= ok_female_AND_male_Years_Work_art_68_3 &&
					retired == false)
				{
					//cout << "year: " << year << ": You CAN RETIRE under art.68_3 at age: " << age / 12 << endl;
					retired = true;
					age_to_retire_Art_68_3 = age;
					year_to_retire_Art_68_3 = year;
				}
				if (year > 2017 && ok_male_pension_age < top_65years_age - 1)
				{
					ok_male_pension_age += 1;
				}

				if (ok_male_pension_Years_Work < top_work_male_40yars - 2)
				{
					ok_male_pension_Years_Work += 2;
				}
				//std::cout << "Your AGE: " << age / 12 << "; " << "years WORK: " << insuranceYears / 12 << ";" << std::endl;
			}

			if (age / 12 > 65)
			{
				printf("In year %d you will be %d years old, will have %d years work, and at last The LAW will allow you to retire. CONGRETS!!\n",
					year, age / 12, insuranceYears / 12);
				std::cout << "BUT..." << std::endl;
				if (start_years_left_to_work_Art_68_3 > 0) {
					printf("If you would like to retire earlier, you can DO IT in year %d, on %d! But you still have %d years left to reach the requirement of minimum 15 working years...\nWill have the lowest pension, sorry.\n\n",
						year_to_retire_Art_68_3, age_to_retire_Art_68_3 / 12, start_years_left_to_work_Art_68_3 / 12);
				}
				else
				{
					printf("If you would like to retire earlier, you can DO IT in year %d, on %d years age! \nWill have the lowest pension, sorry.\n",
						year_to_retire_Art_68_3, age_to_retire_Art_68_3 / 12);
				}
			}
			else
			{
				printf("In year %d you will be %d years old, will have %d years work, and at last The LAW will allow you to retire. CONGRETS!!\n",
					year, age / 12, insuranceYears / 12);
			}
			//CHECK
			//cout << "Gender: " << gender << ";" << " Age: " << age << ";" << " Insurance Years: " << insuranceYears << ";" << endl;
			std::cout << "******************************************************************" << std::endl;
			break;
		}
		}
		std::cout << "1 - female\n2 - male\n0 - Exit\nENTER genrer: ";
		std::cin >> gender;
		std::cin.ignore();
	}
	return 0;
}


