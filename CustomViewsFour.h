/*
	RackAFX(TM)
	Applications Programming Interface
	Derived Class Object Definition
	Copyright(c) Tritone Systems Inc. 2006-2012

	Your plug-in must implement the constructor,
	destructor and virtual Plug-In API Functions below.
*/

#pragma once

// base class
#include "plugin.h"
#include "GUIViewAttributes.h"
#include "WaveFormView.h"
#include "../vstgui4/vstgui/vstgui.h"

class CCustomViewsFour : public CPlugIn
{
public:
	// RackAFX Plug-In API Member Methods:
	// The followung 5 methods must be impelemented for a meaningful Plug-In
	//
	// 1. One Time Initialization
	CCustomViewsFour();

	// 2. One Time Destruction
	virtual ~CCustomViewsFour(void);

	// 3. The Prepare For Play Function is called just before audio streams
	virtual bool __stdcall prepareForPlay();

	// 4. processAudioFrame() processes an audio input to create an audio output
	virtual bool __stdcall processAudioFrame(float* pInputBuffer, float* pOutputBuffer, UINT uNumInputChannels, UINT uNumOutputChannels);

	// 5. userInterfaceChange() occurs when the user moves a control.
	virtual bool __stdcall userInterfaceChange(int nControlIndex);


	// OPTIONAL ADVANCED METHODS ------------------------------------------------------------------------------------------------
	// These are more advanced; see the website for more details
	//
	// 6. initialize() is called once just after creation; if you need to use Plug-In -> Host methods
	//				   such as sendUpdateGUI(), you must do them here and NOT in the constructor
	virtual bool __stdcall initialize();

	// 7. joystickControlChange() occurs when the user moves a control.
	virtual bool __stdcall joystickControlChange(float fControlA, float fControlB, float fControlC, float fControlD, float fACMix, float fBDMix);

	// 8. process buffers instead of Frames:
	// NOTE: set m_bWantBuffers = true to use this function
	virtual bool __stdcall processRackAFXAudioBuffer(float* pInputBuffer, float* pOutputBuffer, UINT uNumInputChannels, UINT uNumOutputChannels, UINT uBufferSize);

	// 9. rocess buffers instead of Frames:
	// NOTE: set m_bWantVSTBuffers = true to use this function
	virtual bool __stdcall processVSTAudioBuffer(float** inBuffer, float** outBuffer, UINT uNumChannels, int inFramesToProcess);

	// 10. MIDI Note On Event
	virtual bool __stdcall midiNoteOn(UINT uChannel, UINT uMIDINote, UINT uVelocity);

	// 11. MIDI Note Off Event
	virtual bool __stdcall midiNoteOff(UINT uChannel, UINT uMIDINote, UINT uVelocity, bool bAllNotesOff);


	// 12. MIDI Modulation Wheel uModValue = 0 -> 127
	virtual bool __stdcall midiModWheel(UINT uChannel, UINT uModValue);

	// 13. MIDI Pitch Bend
	//					nActualPitchBendValue = -8192 -> 8191, 0 is center, corresponding to the 14-bit MIDI value
	//					fNormalizedPitchBendValue = -1.0 -> +1.0, 0 is at center by using only -8191 -> +8191
	virtual bool __stdcall midiPitchBend(UINT uChannel, int nActualPitchBendValue, float fNormalizedPitchBendValue);

	// 14. MIDI Timing Clock (Sunk to BPM) function called once per clock
	virtual bool __stdcall midiClock();


	// 15. all MIDI messages -
	// NOTE: set m_bWantAllMIDIMessages true to get everything else (other than note on/off)
	virtual bool __stdcall midiMessage(unsigned char cChannel, unsigned char cStatus, unsigned char cData1, unsigned char cData2);

	// 16. initUI() is called only once from the constructor; you do not need to write or call it. Do NOT modify this function
	virtual bool __stdcall initUI();

	// Custom GUI
	virtual void* __stdcall showGUI(void* pInfo);

	// Add your code here: ----------------------------------------------------------- //
	// --- our helper
	CVSTGUIHelper m_GUIHelper;
	
	// --- custom waveform view
	CWaveFormView* m_pWaveFormView;

	// physical model functions
	virtual bool __stdcall getAcceleration1();
	virtual bool __stdcall getAcceleration2();
	virtual bool __stdcall getCoordinates();
	virtual bool __stdcall getDistances();
	virtual bool __stdcall updateVelocityAndAccel();
	// length of each pendulum and sliders to control.
	float r1 = 200;
	float r2 = 100;

	// mass of each pendulum bob
	float m1 = 20;
	float m2 = 30;

	// angle in radians
	// measures each pendulum from vertical line through origin 
	// origin is the point each pendulum is tied to.
	float PI = 3.141592;
	float a1 = PI / 4;
	float a2 = PI / 9;
	float a1_velocity = 0;
	float a2_velocity = 0;

	float a1_acceleration;
	float a2_acceleration;
	float g = .08;

	float harmonic1x = 200;
	float harmonic1y = 200;

	float harmonic2x = -200;
	float harmonic2y = 200;

	float gain = .1;
	float x1;
	float x2;
	float y1;
	float y2;
	float r1Scalor;
	float distance1;
	float distance2;


	// END OF USER CODE -------------------------------------------------------------- //


	// ADDED BY RACKAFX -- DO NOT EDIT THIS CODE!!! ----------------------------------- //
	//  **--0x07FD--**

	float r1Slider;
	float distance;
	float wet;
	float dry;
	UINT m_uBoost;
	enum{SWITCH_OFF,SWITCH_ON};
	float m_fMeterValueL;
	float m_fMeterValueR;

	// **--0x1A7F--**
	// ------------------------------------------------------------------------------- //

};
