#include <stdio.h>
#include <iostream>
#include "..\..\Libs\Manus\Manus.h"

using namespace std;

int main() 
{
	//blank session pointer
	manus_session_t sess_t;
	manus_session_t* sess = &sess_t;

	manus_session_t* sessp;
	sessp = new manus_session_t();
	delete sessp;

	//hand pointers
	manus_hand_t lefth, righth; 
	manus_hand_t* leftpt = &lefth;
	manus_hand_t* rightpt = &righth;


	manus_hand_raw_t rightraw;
	manus_hand_raw_t* rightrpt= &rightraw;

	bool iscon, isr;
	
	device_type_t left = GLOVE_LEFT;
	//initialize Manus SDK
	ManusInit(sess);

	
	int inp = 0;
	string in = "0";
	while (inp != 1) {
		iscon = ManusIsConnected(*sess, GLOVE_LEFT);
		isr = ManusIsConnected(*sess, GLOVE_RIGHT);
		std::cout << "manus connected : left -  " << iscon << " right - " << isr << endl;
		cin >> inp;
	}
	inp = 0;
	cout << "right hand vib" << endl;
	while (inp != 1) {
		iscon = ManusIsConnected(*sess, GLOVE_LEFT);
		isr = ManusIsConnected(*sess, GLOVE_RIGHT);
		std::cout << "manus connected : left -  " << iscon << " right - " << isr << endl;
		cin >> inp;
	}
	ManusSetVibration(*sess, GLOVE_RIGHT, 0.75, 200);

	
	inp = 0;
	cout << "left hand vib" << endl;
	while (inp != 1) {
		iscon = ManusIsConnected(*sess, GLOVE_LEFT);
		isr = ManusIsConnected(*sess, GLOVE_RIGHT);
		std::cout << "manus connected : left -  " << iscon << " right - " << isr << endl;
		cin >> inp;
	}
	ManusSetVibration(*sess, GLOVE_LEFT, 0.75, 200);

	cout << "Enter to continue" << endl;
	cin >> inp;
	
	inp = 0;
	cout << "right hand skeleton" << endl;
	while (inp != 1) {
		iscon = ManusIsConnected(*sess, GLOVE_LEFT);
		isr = ManusIsConnected(*sess, GLOVE_RIGHT);
		std::cout << "manus connected : left -  " << iscon << " right - " << isr << endl;
		cin >> inp;
	}

	std::cout << "Get hand val = " << ManusGetHand(*sess, GLOVE_RIGHT, rightpt) << endl;
	std::cout << "Index finger - x,y,z" << endl;
	std::cout << "carpal: " << rightpt->index.carpal.translation.x << ", " << rightpt->index.carpal.translation.y << ", " << rightpt->index.carpal.translation.z << endl;
	std::cout << "distal: " << rightpt->index.distal.translation.x << ", " << rightpt->index.distal.translation.y <<", " << rightpt->index.distal.translation.z << endl;
	std::cout << "middle: " << rightpt->index.intermediate.translation.x << ", " << rightpt->index.intermediate.translation.y << ", " << rightpt->index.intermediate.translation.z << endl;
	std::cout << "proximial: " << rightpt->index.proximal.translation.x << ", " << rightpt->index.distal.translation.y << ", " << rightpt->index.distal.translation.z << endl;

	ManusGetHand(*sess, GLOVE_RIGHT, rightpt);

	ManusGetHandRaw(*sess, GLOVE_RIGHT, rightrpt);
	std::cout << "RAW DATA" << endl;
	inp = 0;

	while (inp != 1) {
		iscon = ManusIsConnected(*sess, GLOVE_LEFT);
		isr = ManusIsConnected(*sess, GLOVE_RIGHT);
		std::cout << "manus connected : left -  " << iscon << " right - " << isr << endl;
		std::cout<< "get hand raw val- "<< ManusGetHandRaw(*sess, GLOVE_RIGHT, rightrpt) << endl;
		std::cout << "Pinky - 0,1" << rightrpt->finger_sensor[0] << "," << rightrpt->finger_sensor[1] << endl;
		std::cout << "Ring - 2,3" << rightrpt->finger_sensor[2] << "," << rightrpt->finger_sensor[3] << endl;
		std::cout << "Middle - 4,5" << rightrpt->finger_sensor[4] << "," << rightrpt->finger_sensor[5] << endl;
		std::cout << "Index - 6,7" << rightrpt->finger_sensor[6] << "," << rightrpt->finger_sensor[7] << endl;
		std::cout << "Thumb - 8,9" << rightrpt->finger_sensor[8] << "," << rightrpt->finger_sensor[9] << endl;
		cin >> inp;
	}

	ManusGetHandRaw(*sess, GLOVE_RIGHT, rightrpt);

	std::cout << "Pinky - 0,1" << rightrpt->finger_sensor[0] << "," << rightrpt->finger_sensor[1] << endl;
	std::cout << "Ring - 2,3" << rightrpt->finger_sensor[2] << "," << rightrpt->finger_sensor[3] << endl;
	std::cout << "Middle - 4,5" << rightrpt->finger_sensor[4] << "," << rightrpt->finger_sensor[5] << endl;
	std::cout << "Index - 6,7" << rightrpt->finger_sensor[6] << "," << rightrpt->finger_sensor[7] << endl;
	std::cout << "Thumb - 8,9" << rightrpt->finger_sensor[8] << "," << rightrpt->finger_sensor[9] << endl;

	std::cin >> inp;
	std::cout << "done" << endl;

	ManusExit(*sess);

	//memory handling
	sess = NULL;
	leftpt = NULL;
	rightpt = NULL;

	return 0;
}