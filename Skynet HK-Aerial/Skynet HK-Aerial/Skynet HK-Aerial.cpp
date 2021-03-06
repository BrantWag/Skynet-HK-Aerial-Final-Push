// Skynet_HK-aerial.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
using std::cout;
using std::endl;

int main()
{
	//generate random enemy location on 8X8 grid.
	cout << "Prisoners are assigned a cell based on a an 8X8 grid. All have been assigned tracking chips as well " << endl;
	srand(time(0)); //random number seeding 
					//randomizing the number between 1-64
					//random number sequence
	int searchGridHighNumber = 64;
	int searchGridLownumber = 1;
	int prisonerlocation = rand() % searchGridHighNumber + searchGridLownumber;
	cout << "The prisoner is located at Cell # " << prisonerlocation
		<< " on 8X8 grid with 1-64 sectors." << endl;
	cout << "Prisoner tracking system online....." << endl; 
	int PrisonerLocationPredictionCounter = 0;
	//is prisoner found / killed
	bool targetfound = false;

	while (targetfound == false)
	{
		// software selecting prison cell prediction in tracking prisoner with chip data.
		int targetLocationPrediction = ((searchGridHighNumber - searchGridLownumber) / 2) + searchGridLownumber;
		PrisonerLocationPredictionCounter++; //targetLocationPredictionCounter = targetLocationPredictionCounter +1;
										   //Radar ping of enemy location
		cout << "==============================================================" << endl;
		cout << "Ptrack sending out ping # " << PrisonerLocationPredictionCounter << endl;
		//Ping tells us 
		//If the Prisoners cell is higer or lower or right on the cell location 
		//Is the Prisoners cell prediction higher then prisoner location 
		if (targetLocationPrediction > prisonerlocation)
		{
			//was higher than the prisoners cell 
			//does not need to search at or above cell number
			searchGridHighNumber = targetLocationPrediction - 1;
			//subtract one dont need to search same number
			cout << "The Ptracks cell prediciton of " << targetLocationPrediction << " was higher than the actual cell location " << prisonerlocation << endl;
			cout << "The new searchGirdNumber = " << searchGridHighNumber << endl;
		}
		else if (targetLocationPrediction < prisonerlocation)
		{
			//the Prioner cell location prediction was lower then prioner location
			//does not need to serach at or below cell number
			searchGridLownumber = PrisonerLocationPredictionCounter ++;
			//add one because we dont need to search same number 
			cout << "The Ptracks cell prediciton of " << targetLocationPrediction << " was lower than the actual cell location " << prisonerlocation << endl;
			cout << "The new searchGridLownumber = " << searchGridLownumber << endl;
		}
		else if (targetLocationPrediction == prisonerlocation)
		{
			//Prisoner was found!!!
			cout << "Prisoner was hiding in cell # " << prisonerlocation << endl;
			cout << "Target was found at cell # " << targetLocationPrediction << endl;
			cout << "Ptrack took " << PrisonerLocationPredictionCounter << " predicitons to find the prisoners location in a Prison cell grid 8x8 (64)" << endl;
			targetfound = true;
		}
		else
		{
			//keeps Ptrack from running forever
			cout << "Software malfunction!!!!" << endl;
			cout << "Send Drone for SoftWare diagnostics!!!" << endl;
			targetfound = true;
		}
	}
	//pause then exit simulation....
	system("pause");
	return 0;
}