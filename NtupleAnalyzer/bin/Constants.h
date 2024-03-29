#ifndef Constants_h
#define Constants_h

// Using the EventData wrapper
#include "EventData.h"
#include "Operation.h"

// Using streams
#include <iostream>
#include <vector>

// ROOT stuff
#include "TFile.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TLorentzVector.h"

using namespace std;

namespace Constants 
{
	
	string outputDir = "/uscms_data/d2/vergili/sep/CMSSW_5_3_3_patch2/src/MonoJetAnalysis/NtupleAnalyzer/";
	string condorOutDir =  "/uscmst1b_scratch/lpc1/3DayLifetime/vergili/condor/"; 
	string condorBin    =  "/uscms_data/d2/vergili/sep/CMSSW_5_3_3_patch2/bin/slc5_amd64_gcc462/"; 
}





#include "Constants.cc"
#endif 
