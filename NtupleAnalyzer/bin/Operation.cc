#include "Operation.h"
#include "Histogram01.h"
#include "Histogram02.h"
#include <iostream>
#include <fstream>

#include <TH1D.h>
#include <math.h>
#include <TLorentzVector.h>

#include <memory>

#include "DataFormats/Math/interface/deltaR.h"
#include "DataFormats/Math/interface/deltaPhi.h"

using namespace std;


///-----------------------------------------------------------------------------------------------------------------

namespace Operation 
{

	vector<double> generate_flat10_weights(TH1D* data_npu_estimated)
	{
	  
	  //Array for 1D  reweight 
    const double npu_probs[60] = 
		{
			3.10347e-05,
			6.78815e-05,
			0.000150129,
			0.000295762,
			0.000491949,
			0.000773783,
			0.00114708,
			0.00167576,
			0.00241632,
			0.0034114,
			0.00468821,
			0.00635805,
			0.00833243,
			0.0106723,
			0.0134027,
			0.0164735,
			0.0195376,
			0.022991,
			0.0262165,
			0.029431,
			0.0323909,
			0.0351272,
			0.0374332,
			0.0394877,
			0.0409591,
			0.0419383,
			0.0426948,
			0.0427961,
			0.0426697,
			0.0418952,
			0.040996,
			0.0395511,
			0.037894,
			0.0359037,
			0.0336904,
			0.0313308,
			0.0288144,
			0.0262867,
			0.0236899,
			0.0211874,
			0.0186044,
			0.0163021,
			0.014236,
			0.0120566,
			0.0102604,
			0.00862128,
			0.00722878,
			0.00589933,
			0.00478757,
			0.00393351,
			0.0031027,
			0.00245733,
			0.00193895,
			0.00150304,
			0.00115026,
			0.000848245,
			0.000654251,
			0.000483286,
			0.00036781,
			0.000263082,
		}; 
		//Official Pileup
		/*const double npu_probs[60] = 
		{
			2.344E-05,
            2.344E-05,
            2.344E-05,
            2.344E-05,
            4.687E-04,
            4.687E-04,
            7.032E-04,
            9.414E-04,
            1.234E-03,
            1.603E-03,
            2.464E-03,
            3.250E-03,
            5.021E-03,
            6.644E-03,
            8.502E-03,
            1.121E-02,
            1.518E-02,
            2.033E-02,
            2.608E-02,
            3.171E-02,
            3.667E-02,
            4.060E-02,
            4.338E-02,
            4.520E-02,
            4.641E-02,
            4.735E-02,
            4.816E-02,
            4.881E-02,
            4.917E-02,
            4.909E-02,
            4.842E-02,
            4.707E-02,
            4.501E-02,
            4.228E-02,
            3.896E-02,
            3.521E-02,
            3.118E-02,
            2.702E-02,
            2.287E-02,
            1.885E-02,
            1.508E-02,
            1.166E-02,
            8.673E-03,
            6.190E-03,
            4.222E-03,
            2.746E-03,
            1.698E-03,
            9.971E-04,
            5.549E-04,
            2.924E-04,
            1.457E-04,
            6.864E-05,
            3.054E-05,
            1.282E-05,
            5.081E-06,
            1.898E-06,
            6.688E-07,
            2.221E-07,
            6.947E-08,
            2.047E-08
		};*/
		vector<double> result(60);

		double s = 0.0;
		for(int npu=0; npu<60; ++npu)
		{
			double npu_estimated = data_npu_estimated->GetBinContent(data_npu_estimated->GetXaxis()->FindBin(npu));
			result[npu] = npu_estimated / npu_probs[npu];
			s += npu_estimated;
		}
		// normalize weights such that the total sum of weights over thw whole sample is 1.0, i.e., sum_i  result[i] * npu_probs[i] should be 1.0 (!)
		for(int npu=0; npu<60; ++npu)
		{
			result[npu] /= s;
		}
		return result;
	}


	///-------------------PF  Lepton selection----------------------------------------------

	bool PFMuonTightCuts(EventData& ev , int i, double pt)
	{

		bool  pass    = false;
		//float dxy     = ev.PFMuondxy(i);
		//float dz      = ev.PFMuondz(i);
		bool  passIso = false;
		bool  passKin = false;
		//bool  passVtx = false;
		bool  passID  = false;
	
		float Iso = 0.0;
		Iso = (ev.PFMuonNeutralHadronIso(i) + ev.PFMuonChargedHadronIso(i) + ev.PFMuonPhotonIso(i))/ev.PFMuonPt(i);
	
		if(Iso <  0.2 ) passIso = true;
	
		//if(ev.PFMuonPt(i) > 20. && fabs(ev.PFMuonEta(i)) < 2.4 )
		if(ev.PFMuonPt(i) > pt && fabs(ev.PFMuonEta(i)) < 2.1 )  
		passKin = true;


		//if(fabs(dxy) < 0.02  && fabs(dz) < 1.0 ) passVtx = true;

		//if(ev.PFMuonisGMPT(i) && ev.PFMuonnValidHits(i) >= 11 ) passID = true;


		if( ev.PFMuonIsTracker(i)==1 && 
			ev.PFMuonIsGlobal(i)==1 && 
			ev.PFMuonNumOfMatches(i)>1  && 
			ev.PFMuonCombChi2Norm(i) < 10.0  &&
			ev.PFMuonTrkDxy(i)< 0.2 && 
			ev.PFMuonTrkValidHits(i) > 10 && 
			ev.PFMuonTrkNumOfValidPixHits(i) > 0  &&  
			ev.PFMuonStandValidHits(i) >0 )  passID = true; 
	

		if(passKin && passIso && passID) pass = true;

		
	
		return pass; 
	
	}	

	///-------------------PF  Lepton selection----------------------------------------------

	bool PFElecTightCuts(EventData& ev , int i, double pt)
	{

		// kinematic and fiducial
		float cutE_pt              = pt;
		float cutE_eta             = 2.5;
		float cutE_etagap[2]       = {1.4442,1.5666};
		
		//WP80 ID
		float cutE_EB_hadem        = 0.04;
		float cutE_EE_hadem        = 0.025;
		
		//float cutE_EB_combiso      = 0.07;
		//float cutE_EE_combiso      = 0.06;
		
		float cutE_EB_ietaieta     = 0.01;
		float cutE_EE_ietaieta     = 0.03;
		
		float cutE_EB_deta         = 0.004;
		float cutE_EE_deta         = 0.007;
		
		float cutE_EB_dphi         = 0.06;
		float cutE_EE_dphi         = 0.03;
		
		float cutE_dxy             = 0.02;
		float cutE_dz              = 1.0;
		
		//conversion rejection
		int cutE_innerhits         = 0;
		float cutE_dcot            = 0.02;
		float cutE_dist            = 0.02;
		
		//PF ID
		float cutE_EB_combiso_PF   = 0.2;
		//float cutE_EE_combiso_PF   = 0.11;
		
		//float cutE_EB_MVA_PF       = 0.34;
		//float cutE_EE_MVA_PF       = 0.32;

		bool useWP95ID = false;

		/*if(useWP95ID){

			float cutE_EB_hadem        = 0.15;
			float cutE_EE_hadem        = 0.07;
			
			float cutE_EB_ietaieta     = 0.01;
			float cutE_EE_ietaieta     = 0.03;
			
			float cutE_EB_deta         = 0.007;
			float cutE_EE_deta         = 0.01;
			
			float cutE_EB_dphi         = 0.8;
			float cutE_EE_dphi         = 0.7;
			
			float cutE_dxy             = 0.02;
			float cutE_dz              = 1.0;
			
			//conversion rejection
			int cutE_innerhits         = 1;
			float cutE_dcot            = 0.02;
			float cutE_dist            = 0.02;
			
			//PF ID
			float cutE_EB_combiso_PF   = 0.2;
			//float cutE_EE_combiso_PF   = 0.11;
		}*/

		bool pass      = false;
		bool passID    = false;
		bool passIso   = false;
		bool passKin   = false;
		bool passCR    = false;
		//bool conv      = false;
		bool passVtx   = false;
		float Iso      = 0.0;
		float dxy      = ev.PFElecdxy(i);
		float dz       = ev.PFElecdz(i);
		int innerhits  = ev.PFElecInnerHits(i);
		float ietaieta = ev.PFElecietaieta(i);
		float deltaphi = ev.PFElecDPhiSuTrAtVtx(i);
		float deltaeta = ev.PFElecDEtaSuTrAtVtx(i);
		float hadEm    = ev.PFElecHcalOverEcal(i);


	
		Iso = (ev.PFElecNeuHadIso(i) + ev.PFElecCharHadIso(i) + ev.PFElecPhoIso(i) )/ev.PFElecPt(i);

		if(Iso < cutE_EB_combiso_PF) passIso = true;
	
		if(ev.PFElecPt(i) > cutE_pt && fabs(ev.PFElecEta(i) ) < cutE_eta && (fabs(ev.PFElecEta(i)) < cutE_etagap[0] || 
		fabs(ev.PFElecEta(i)) > cutE_etagap[1]))
		passKin = true;

		//		if(ev.PFElecIsEB(i) == 1 && ev.PFElecMva(i) > cutE_EB_MVA_PF) passID =true;
		//		if(ev.PFElecIsEB(i) != 1 && ev.PFElecMva(i) > cutE_EE_MVA_PF) passID =true;

		if((ev.PFElecIsEB(i) == 1 && 
		    ietaieta < cutE_EB_ietaieta && 
		    fabs(deltaphi) <  cutE_EB_dphi &&
		    fabs(deltaeta) < cutE_EB_deta && 
		    hadEm < cutE_EB_hadem) ||
		   (ev.PFElecIsEB(i) != 1 && 
		    ietaieta < cutE_EE_ietaieta && 
		    fabs(deltaphi) < cutE_EE_dphi &&
		    fabs(deltaeta) <  cutE_EE_deta && 
		    hadEm <  cutE_EE_hadem))
		  passID = true;

		if(!useWP95ID){
		  if(innerhits <= cutE_innerhits && !(fabs(ev.PFElecConvDcot(i)) < cutE_dcot && fabs(ev.PFElecConvDist(i) ) < cutE_dist))
		    passCR = true;
		}
		else{
		  if(innerhits <= cutE_innerhits)
		    passCR = true;
		}
	
		if(fabs(dxy) < cutE_dxy && fabs(dz) < cutE_dz)
		passVtx = true;
	
		if(passIso && passID && passCR && passKin && passVtx) pass = true;

		return pass;
	
	}	


	///-------------------PF  Lepton selection----------------------------------------------

	bool PFLepTightCuts(EventData& ev , int i, double pt)
	{
		bool send=false;

		if(ev.LepType()=="m" )
		{
			send = PFMuonTightCuts( ev , i, pt);
	
		}
		else if(ev.LepType()=="e")
		{
			
			send = PFElecTightCuts( ev , i, pt);

		}
		return send;
	}	




	///-------------------isolated  muon selection----------------------------------------------

	bool IsIsoMuon(int i , EventData & ev)
	{
	  	if(ev.MuonIsTracker(i)==0 || ev.MuonIsGlobal(i)==0 || ev.MuonNumOfMatches(i)<2  || ev.MuonCombChi2Norm(i) >10.0  || 
		ev.MuonTrkDxy(i)>0.2 || ev.MuonTrkValidHits(i) < 10 || ev.MuonTrkNumOfValidPixHits(i) < 1  ||  ev.MuonStandValidHits(i) <1  || 
		ev.MuonPt(i)<20.0 || 
		abs( ev.MuonEta(i) ) > 2.1 ||
		(ev.MuonHadEtDR03(i)+ ev.MuonEmEtDR03(i)+ev.MuonSumPtDR03(i))/ev.MuonPt(i) > 0.15  )
		{
			return false;
		}
		else
		{
			return true;   // this is isolated muon 
		} 
	}


	bool IsIsoMuonWithoutEta(int i , EventData & ev)
	{
	  	if(ev.MuonIsTracker(i)==0 || ev.MuonIsGlobal(i)==0 || ev.MuonNumOfMatches(i)<2  || ev.MuonCombChi2Norm(i) >10.0  || 
		ev.MuonTrkDxy(i)>0.2 || ev.MuonTrkValidHits(i) < 10 || ev.MuonTrkNumOfValidPixHits(i) < 1  ||  ev.MuonStandValidHits(i) <1  || 
		ev.MuonPt(i)<20.0 ||
		(ev.MuonHadEtDR03(i)+ ev.MuonEmEtDR03(i)+ev.MuonSumPtDR03(i))/ev.MuonPt(i) > 0.15  )
		{
			return false;
		}
		else
		{
			return true;   // this is isolated muon 
		} 
	}

	///------------------Lepton in  jet-----------------------------------------------------------

	bool LepInJet(double JetEta , double JetPhi ,   EventData & ev)
	{
		bool send=false;

		for(int i=0; i<ev.NPFMuon(); i++ )
		{
			if( PFMuonTightCuts(ev ,i) &&  deltaR( JetEta , JetPhi , ev.PFMuonEta(i) , ev.PFMuonPhi(i) ) < 0.3)
			{	
				send= true;  // this jet has iso muon
			}
		}
		for(int i=0; i<ev.NPFElec(); i++ )
		{
			if( PFElecTightCuts(ev ,i) &&  deltaR( JetEta , JetPhi , ev.PFElecEta(i) , ev.PFElecPhi(i) ) < 0.3)
			{	
				send= true;  // this jet has iso elec
			}
		}

		
		return send;
	}
	
	///-------------------MET+mu-----------------------------------------------------------------

	double  MetLepPt(double MetPx , double MetPy , EventData & ev)
	{
		double Metx = MetPx;
		double Mety = MetPy;

		if( ev.MetType()>9)  // pf or tc Met
		{
			for(int i=0; i<ev.NPFLep(); i++ )
			{
				if( PFLepTightCuts(ev ,i ) )
				{
					Metx =  Metx + ev.PFLepPx(i);
					Mety =  Mety + ev.PFLepPy(i);
				}
			}
		}
		
		return sqrt( Metx*Metx + Mety*Mety );
	}

	///----------------MET+mu Phi--------------------------------------------------------------
	
	double  MetLepPhi(double MetPx , double MetPy , EventData & ev)
	{
		double Metx = MetPx;
		double Mety = MetPy;
		
		if( ev.MetType()>9)  // pf or tc Met 
		{
			for(int i=0; i<ev.NPFLep(); i++ )
			{
				if( PFLepTightCuts(ev ,i) )
				{  
					Metx =  Metx + ev.PFLepPx(i);
					Mety =  Mety + ev.PFLepPy(i);
				}
			}
		}	
		
		return atan2( Mety,Metx);  
	}


	
	///------------------JetIndex Selection------------------------------------------------------

	int JetIndex(int ind, EventData & ev)
	{
		int send= 99;
		if( ev.JetType()=="calo")
		{
			int njets=0;
			for (int i=0; i<ev.NCaloAK5Jets(); i++)
			{
				if( ev.CaloAK5JetPtCor(i)>ev.SecJetCut()  )
				{
					if(njets==ind)send=i;
					njets++ ;
				}
			}
		}
		if( ev.JetType()=="pf")
		{
			int njets=0;
			for (int i=0; i<ev.NPFAK5Jets(); i++)
			{
				if( ev.PFAK5JetPtCor(i)>ev.SecJetCut() && abs(ev.PFAK5JetEta(i))< 4.5
					 && LepInJet(ev.PFAK5JetEta(i) , ev.PFAK5JetPhi(i) , ev )==false )
				{
					if(njets==ind)send=i;
					njets++ ;
				}
			}
		}
		
		return send; 
	}
	
	///-------------------------Find Number of Jets---------------------------------------------

	int JetNumber(EventData & ev)
	{
		int njets=0;
		
		if( ev.JetType()=="calo")
		{
			for (int i=0; i<ev.NCaloAK5Jets(); i++)
			{
				if( ev.CaloAK5JetPtCor(i)>ev.SecJetCut()  )
				{
					njets++ ;
				}
			}
		}
		if( ev.JetType()=="pf")
		{
			for (int i=0; i<ev.NPFAK5Jets(); i++)
			{
				if( ev.PFAK5JetPtCor(i)>ev.SecJetCut() && abs(ev.PFAK5JetEta(i)) < 4.5
					&& LepInJet(ev.PFAK5JetEta(i) , ev.PFAK5JetPhi(i) , ev )==false )
				{
					njets++ ;
				}
			}
		}
		
		return njets; 
			
	}
    

///--------------------------------------------------------------------------------------------------------

	Manager::Manager(const std::string & logFileName) : mLogFileName(logFileName){}

	Manager::~Manager() {}

	void Manager::Add(Operation::_Base * aOp) 
	{
		Manager::OpData tempData;
		tempData.op = aOp;
		tempData.ng = 0.0;
		mOperations.push_back(tempData);
	}

///-------------------------------------------------------------------------------------------------------

	void Manager::Run(EventData & ev) 
	{

		// Clear counters
		double ng_all = 0.0;
		double ng_total = 0.0;
		std::vector<Manager::OpData>::iterator i = mOperations.begin();
		
		while ( i != mOperations.end() ) 
		{
			i->ng = 0.0;
			++i;
		}

		// Main event loop
		// Just keep going until max events is hit or we finish the file
		while ( ev.GetNextEvent() )
		{
			// Sum the total event weight
			ng_all += ev.Weight();

			// Loop over the operations
			i = mOperations.begin();
			while ( i != mOperations.end() ) 
			{
				// Call the filter

				if ( !i->op->Process(ev) ) break; // break on failure

				// Filter passed, save weight
				i->ng += ev.Weight();

				++i;
			}

			// If we aren't at the end continue without adding total
			if ( i != mOperations.end() ) continue;

			// Sum the total that passes all the operations
			ng_total += ev.Weight();




// 			int flg_trg80=0;
// 			string strtrg = ev.HLTNames();
//			if (strtrg.find("HLT_CentralJet80_MET80")!=string::npos ) flg_trg80=1;


			
			//int ixjet1= JetIndex(0, ev);
			//int ixjet2= JetIndex(1, ev);

			//if(flg_trg80==0) cout << "\"" << ev.run()  <<  ":"  << ev.event() <<  "\",    " <<  ev.run() <<  "," << ev.lumi() <<   endl;
			//else cout << "..............\"" << ev.run()  <<  ":"  << ev.event() <<  "\",    " <<  ev.run() <<  "," << ev.lumi() <<   endl;

			//cout << ev.run()  <<  "    "  << ev.lumi() << "    "  <<   ev.event() <<   endl;


			//cout << "CALO:" << ev.MetPt(0)  <<  "   PF:"  << ev.MetPt(10) <<  "  TC:" <<  ev.MetPt(20)  <<   endl;
		
			//cout<< MetMuPt( ev.MetPx(10) , ev.MetPy(10) , ev )  << "  Tiv: " << ev.LowTIV()  <<  " DeltaPhi:  "  <<  deltaPhi( ev.PFAK5JetPhi(ixjet1) ,  ev.PFAK5JetPhi(ixjet2) )  << "  jetPt: "  <<  ev.PFAK5JetPtCor(ixjet1) <<  "   "    << ev.PFAK5JetPtCor(ixjet2)   <<endl; 


			//cout << ev.PFLepPy(1) << " " << ev.PFMuonPy(1) <<  " "  <<  ev.NPFLep() <<  " " <<  ev.NPFMuon() <<   endl; 

			/*for(int i=0; i<100; i++){

			   double w = ev.PDFWeight(i) * ev.PDFWeights(0) /ev.PDFWeight(0);

			   //double w = ev.PDFWeightAlphaS(i) * ev.PDFWeights(0) / ev.PDFWeightAlphaS(0);

			  //cout <<  w <<  "   " << ev.PDFWeight(i)  <<  "   " << ev.PDFWeight(i) <<  "   ..."  << ev.PDFWeights(i)  <<  endl;

			   
			  //cout << "----------------------------" <<  endl;
			}
			cout << "----------------------------" <<  endl;  
			*/


			//cout << ev.PFLepPt(0)  <<  "  " <<  ev.LepType()  <<  "  " <<   PFElecTightCuts(ev , 0)  << endl;


			/*for(int i=0; i<ev.NGenPar(); i++)
			{

	   
			  //if( ( abs(ev.GenParId(i) )>10 || abs(ev.GenParId(i) ) <17 ) && ev.GenParStatus(i)==1  )
		            {
			      cout <<   ev.GenParId(i)  << "   mother:" <<  ev.GenParDoughterOf(i)  <<  "  pt:" << ev.GenParPt(i) << endl;

		            }
		        }*/
			
		}

		// Output the information about the run to the log file
		OutputResults(mLogFileName.c_str(), ng_all, ng_total);

	}


///-----------------------------------------------------------------------------------------------------------------------------------

	void Manager::OutputResults(const std::string & dataSet, double ng_all, double ng_total) 
	{
		ofstream outfile(mLogFileName.c_str(), ios::app);

// 		cout << "Dataset info recorded in: " << dataSet << endl;
// 		cout << "Total events processed by all operations: " << ng_all << endl;
// 		cout << "Total events passing all operations: " << ng_total << endl;
// 
// 		outfile << "Dataset info recorded in: " << dataSet << endl;
// 		outfile << "Total events processed by all operations: " << ng_all << endl;
// 		outfile << "Total events passing all operations: " << ng_total << endl;
 
 		std::vector<Manager::OpData>::iterator i = mOperations.begin();
 		while ( i != mOperations.end() ) 
 		{
 			cout << "Events surviving " << *(i->op) << ": " << i->ng  << endl;
			outfile << "Events surviving " << *(i->op)  << ": " << i->ng << endl;
 
 			++i;
 		}

		 

	}


///----------------------------------------------------------------------------------------------------

	_Base::_Base() {}
	_Base::~_Base(){}

	// Just definition of the operator
	std::ostream& operator << (std::ostream& ostrm, _Base& m) 
	{
		return m.Description(ostrm);
	}




//--------------------------CUTS STARTING FROM HERE-----------------------------------------------------

///--------------------------ABnormal Events -----------------------------------------------------------


	CutAbnormalEvents::CutAbnormalEvents(vector<int> run ,vector<int> evt ) : mRun(run) , mEvt(evt) {} 
	CutAbnormalEvents::~CutAbnormalEvents() {}

	bool CutAbnormalEvents::Process(EventData & ev) 
	{
	        if(  abs(ev.MetPt(10) - ev.MetPt(0))< 1.5*ev.MetPt(0)  )
		{
			return true;
		} 
		else 
		{
			return false;
		}

	}
	std::ostream& CutAbnormalEvents::Description(std::ostream &ostrm) 
	{
	        ostrm << "  Abnormal Events"   << "" << ":............";
		return ostrm;
	}
	
	
///--------------------------HLT Cut--------------------------------------------------------------------


	CutHLT::CutHLT(int bit) : mBit(bit) {} 
	CutHLT::~CutHLT() {}

	bool CutHLT::Process(EventData & ev) 
	{

		//int flg_trg=0;
		//string strtrg = ev.HLTNames();
		//if (strtrg.find("HLT_CentralPFJet80_CaloMET50_dPhi1_PFMHT80")!=string::npos ) flg_trg=1;

		//bit-3 is  beamHalo Tight 

	    if( ev.NoiseFlag(0)==0 ||  ev.NoiseFlag(1)==0 ||  ev.NoiseFlag(2)==0 ||  ev.NoiseFlag(3)==0 ||
            ev.NoiseFlag(4)==0 ||  ev.NoiseFlag(5)==0 ||  ev.NoiseFlag(6)==0 ||  ev.NoiseFlag(7)==0 )
		{
			return false;
		} 
		else 
		{
			return true;
		}



	}
	std::ostream& CutHLT::Description(std::ostream &ostrm) 
	{
		ostrm << "  HLT Bit-" << mBit << ":............";
		return ostrm;
	}


///--------------------------MET Cut-------------------------------------------------------------------------

	CutMet::CutMet(double cut, bool nolep = 0) : mCut(cut), mNoLep(nolep) {} 
	CutMet::~CutMet() {}

	bool CutMet::Process(EventData & ev) 
	{
		if( (mNoLep == 0 && MetLepPt( ev.MetPx(ev.MetType()) , ev.MetPy(ev.MetType()) , ev )  > mCut ) || 
			(mNoLep == 1 && ev.MetPt( ev.MetType() ) > mCut) )
		{
			
			return true;
		} 
		else 
		{
			return false;
		}
	}
	std::ostream& CutMet::Description(std::ostream &ostrm) 
	{
		ostrm << "  Met"   << "Cut met >" << mCut << " GeV :............";
		return ostrm;
	}

///--------------------------NOISE CLEAN Cut---------------------------------------------------------------


	CutNoiseClean::CutNoiseClean(double JetfHPD , double JetfRBX, int JetN90Hits,  double  JetEmfMin, double JetEmfMax ) : 
	mJetfHPD(JetfHPD) , mJetfRBX(JetfRBX), mJetN90Hits(JetN90Hits),  mJetEmfMin(JetEmfMin), mJetEmfMax(JetEmfMax) {} 
	CutNoiseClean::~CutNoiseClean() {}

	bool CutNoiseClean::Process(EventData & ev) 
	{
		bool send=false;

	  	if( ev.JetType()=="calo")
		{
			if(ev.CaloAK5JetIDTIGHT(0)==1)
			{
				send=true;
			}
		}
		
		else if(ev.JetType()=="pf")
		{
		  	int ixjet1= JetIndex(0, ev);
			int ixjet2= JetIndex(1, ev);

			//if( JetNumber(ev)==1 && ev.PFAK5JetChaHadEngFrac(ixjet1)>0.2 &&  ev.PFAK5JetNeuHadEngFrac(ixjet1)<0.7 &&
			//  ev.PFAK5JetChaEmEngFrac(ixjet1)<0.7  && ev.PFAK5JetNeuEmEngFrac(ixjet1)<0.7  )
			  
			if( JetNumber(ev)==1 
				&& ev.PFAK5JetChaHadEngFrac(ixjet1) > 0.2
				&& ev.PFAK5JetNeuHadEngFrac(ixjet1)< 0.7
				&& ev.PFAK5JetChaEmEngFrac(ixjet1) < 0.7
				&& ev.PFAK5JetNeuEmEngFrac(ixjet1) < 0.7
				)
			{
				send=true;
			} 

			if( ixjet2<99 && ixjet1<99 &&  JetNumber(ev)>1 
				&& ev.PFAK5JetChaHadEngFrac(ixjet1) > 0.2
				&& ev.PFAK5JetNeuHadEngFrac(ixjet1)< 0.7
				&& ev.PFAK5JetChaEmEngFrac(ixjet1) < 0.7
				&& ev.PFAK5JetNeuEmEngFrac(ixjet1) < 0.7
				&& ev.PFAK5JetNeuHadEngFrac(ixjet2)< 0.7
				)
			{
				send=true;
			}
		 

		}

		
		return send;

	}
	std::ostream& CutNoiseClean::Description(std::ostream &ostrm) 
	{
		ostrm << "  NoiseClean Cut "  << " :............";
		return ostrm;
	}	

///--------------------------NJet Cut------------------------------------------------------------------


	CutNJet::CutNJet(int cut) : mCut(cut) {} 
	CutNJet::~CutNJet() {}

	bool CutNJet::Process(EventData & ev) 
	{
		
		bool send=false;

		if( ev.JetType()=="calo")
		{
			if ( JetNumber(ev)>0 && JetNumber(ev)< mCut )
			{
				send=true;
			} 
		}
		else if( ev.JetType()=="pf")
		{
			//to select second jet with eta cut
			/*int njets2=0;
			for (int i=0; i<ev.NPFAK5Jets(); i++)
			{	
				if( ev.PFAK5JetPtCor(i)>30.0  &&  abs(ev.PFAK5JetEta(i))<2.5  )
				{
					njets2++;
				}
			}*/

			if ( JetNumber(ev)>0 && JetNumber(ev)< mCut )
			{
				send=true;
			} 
		}

		
		return send; 
	}
	std::ostream& CutNJet::Description(std::ostream &ostrm) 
	{
		ostrm << "  NJet"   <<  " Cut  njet<" << mCut << " :............";
		return ostrm;
	}
	
	

///--------------------------JET1 CUT--------------------------------------------------------------------


	CutJet1::CutJet1(double JetPt , double JetEta, double  JetIDEmfMin, double JetIDEmfMax ) : 
	mJetPt(JetPt) , mJetEta(JetEta), mJetIDEmfMin(JetIDEmfMin),  mJetIDEmfMax(JetIDEmfMax) {} 
	CutJet1::~CutJet1() {}

	bool CutJet1::Process(EventData & ev) 
	{
		bool send=false;
	  	if( ev.JetType()=="calo")
		{
			if( ev.CaloAK5JetPtCor(0)>mJetPt &&  abs(ev.CaloAK5JetEta(0))<mJetEta )
			{
				send=true;
			}
		}
		else if(ev.JetType()=="pf")
		{
		  	int ixjet1= JetIndex(0, ev);

			if( ixjet1<99 &&  ev.PFAK5JetPtCor(ixjet1)>mJetPt && abs(ev.PFAK5JetEta(ixjet1))<mJetEta  )
			//if( ev.CaloAK5JetPtCor(0)>mJetPt && abs(ev.CaloAK5JetEta(0))<mJetEta )
			{
				send=true;
			}
		}

		
		return send;

	}
	std::ostream& CutJet1::Description(std::ostream &ostrm) 
	{
		ostrm << "  Jet1Cut...  Jet1Pt>" << mJetPt << "  |Jet1Eta|<"<<  mJetEta <<"  " << mJetIDEmfMin <<  "<JetIDEmf<" << mJetIDEmfMax  << " :............";
		return ostrm;
	}	

///--------------------------DeltaPhi-1 Cut----------------------------------------------------------


	CutDeltaPhi1::CutDeltaPhi1(double cut1) : 
	mCut1(cut1){} 
	CutDeltaPhi1::~CutDeltaPhi1() {}

	bool CutDeltaPhi1::Process(EventData & ev) 
	{
		bool send=false;
	  	if( ev.JetType()=="calo")
		{
			if( abs( deltaPhi( ev.CaloAK5JetPhi(0), MetLepPhi( ev.MetPx(ev.MetType()) , ev.MetPy(ev.MetType()) , ev ) ) ) >mCut1  ) 
			{
			       send=true;
			}
		}
		if( ev.JetType()=="pf")
		{
		  	int ixjet1= JetIndex(0, ev);

			if(ixjet1<99 &&   abs( deltaPhi( ev.PFAK5JetPhi(ixjet1), MetLepPhi( ev.MetPx(ev.MetType()) , ev.MetPy(ev.MetType()) , ev ) ) ) <mCut1  )
			{
				send=true;
			}
			
		}

		
		return send;
	}
	std::ostream& CutDeltaPhi1::Description(std::ostream &ostrm) 
	{
		ostrm << "  DeltaPhi-1 Cut   dPhi(Jet1,Met)>" <<  mCut1 --<< " :............";
		return ostrm;
	}


///--------------------------DeltaPhi-2 Cut----------------------------------------------------------------


	CutDeltaPhi2::CutDeltaPhi2(double cut1) : 
	mCut1(cut1) {} 
	CutDeltaPhi2::~CutDeltaPhi2() {}

	bool CutDeltaPhi2::Process(EventData & ev) 
	{
		bool  send=false;
	  	if( ev.JetType()=="calo")
		{
			bool  accept =false;
			if(JetNumber(ev)==1) accept =true;
			if(JetNumber(ev)==2 && abs( deltaPhi( ev.CaloAK5JetPhi(1), MetLepPhi( ev.MetPx(ev.MetType()) , ev.MetPy(ev.MetType()) , ev ) ) ) >mCut1 ) accept=true;
			  
			if(accept)
			{
				send=true;
			}
			
		}
		if( ev.JetType()=="pf")
		{
			bool  accept =false;
			int ixjet2= JetIndex(1, ev);
						
			if(JetNumber(ev)==1) accept =true;
			if(ixjet2<99 &&  JetNumber(ev)>1 && abs( deltaPhi( ev.PFAK5JetPhi(ixjet2), MetLepPhi( ev.MetPx(ev.MetType()) , ev.MetPy(ev.MetType()) , ev ) ) ) >mCut1 ) accept=true;
			
			if(accept)
			{
				send=true;
			}
		}

		
		return send;
	}
	std::ostream& CutDeltaPhi2::Description(std::ostream &ostrm) 
	{
		ostrm << "  DeltaPhi-2 Cut   dPhi(Jet2, Met)>"  << mCut1 << " :............";
		return ostrm;
	}
	
	
///--------------------------DeltaPhi-3 Cut---------------------------------------------------------------------------------


	CutDeltaPhi3::CutDeltaPhi3(double cut1) : 
	mCut1(cut1) {} 
	CutDeltaPhi3::~CutDeltaPhi3() {}

	bool CutDeltaPhi3::Process(EventData & ev) 
	{
		bool  send=false;
	  	if( ev.JetType()=="calo")
		{
			bool  accept =false;
	
			if(JetNumber(ev)==1) accept =true;
			if(JetNumber(ev)>1 && abs( deltaPhi( ev.CaloAK5JetPhi(1) , ev.CaloAK5JetPhi(2) ) )  >mCut1 ) accept=true;
			  
			if(accept)
			{
				send=true;
			}
		}
		if( ev.JetType()=="pf")
		{
			bool  accept =false;
		  	int ixjet1= JetIndex(0, ev);
			int ixjet2= JetIndex(1, ev);			
			
			if(JetNumber(ev)==1) accept =true;
			if(ixjet2<99 && ixjet1<99 &&   JetNumber(ev)>1 && abs( deltaPhi( ev.PFAK5JetPhi(ixjet1),  ev.PFAK5JetPhi(ixjet2)  ) ) < mCut1 ) accept=true;
			
			//if( ev.NPFAK5Jets()==1) accept =true;
                        //if(   ev.NPFAK5Jets()>1  && abs( deltaPhi( ev.PFAK5JetPhi(0),  ev.PFAK5JetPhi(1) )) < mCut1 ) accept=true;


			if(accept)
			{
				send=true;
			}	
		}


		return send;
	}
	std::ostream& CutDeltaPhi3::Description(std::ostream &ostrm) 
	{
		ostrm << "  DeltaPhi-3 Cut   dPhi(Jet1, Jet2)>"  << mCut1 << " :............";
		return ostrm;
	}	
	
	
///--------------------------MuonIsolation Cut--------------------------------------------------------------


	NoIsoMuon::NoIsoMuon(double pt) : mPt(pt) {} 
	NoIsoMuon::~NoIsoMuon() {}

	bool NoIsoMuon::Process(EventData & ev) 
	{
		bool  send=true;
		for(int i=0; i<ev.NMuon(); i++ )
		{
			if( IsIsoMuonWithoutEta(i,ev) )
			{
			      send=false;
			}
		}
		return send;
	}
	std::ostream& NoIsoMuon::Description(std::ostream &ostrm) 
	{
		ostrm << "  Muon Iso  muon pt>" <<  mPt << " GeV :............";
		return ostrm;
	}	

///-------------------------MuonIsolation for WZ analysis-------------------------------------------------


	IsoMuon::IsoMuon(double pt) : mPt(pt) {} 
	IsoMuon::~IsoMuon() {}

	bool IsoMuon::Process(EventData & ev) 
	{
	    bool  send=false;
		for(int i=0; i<ev.NMuon(); i++ )
		{
			if( IsIsoMuon(i,ev) )
			{
			      send=true;
			}
		}
		return send;
	  
	}
	std::ostream& IsoMuon::Description(std::ostream &ostrm) 
	{
		ostrm << "  Muon Iso for WZ analysis  muon pt>" <<  mPt << " GeV :............";
		return ostrm;
	}	




///--------------------------TIV Cut----------------------------------------------------------------------

	CutTIV::CutTIV(double cut) : mCut(cut){} 
	CutTIV::~CutTIV() {}

	bool CutTIV::Process(EventData & ev) 
	{

	        //double LowTIV=0;

		float Lower_TIV = 100;
		float ILV_isoPT;
		
		float TIV_pt_l_thr = 10;
		float TIV_pt_s_thr = 1;
		//float TIV_dxy_thr = 100;
		//float TIV_dz_thr = 100;
		float TIV_dR_inner_thr = 0.02;
		float TIV_dR_outer_thr = 0.3;
	

		for(int tl=0; tl<ev.TIV_N(); tl++)
		{
			ILV_isoPT = 100.;


			bool isMuon=false;
			for(int mu=0; mu<ev.NMuon(); mu++)
			  {
			    
			    if( ev.MuonPt(mu) > 20 )   
			      {
				if( ev.MuonSumPtDR03(mu) >= 0 && ev.MuonSumPtDR03(mu) < 100)
				  {
				    float dPhi = deltaPhi( ev.MuonPhi(mu), ev.TIV_phi(tl) );
				    float dEta = ev.MuonEta(mu) - ev.TIV_eta(tl);
				    if( sqrt(dPhi*dPhi + dEta*dEta) < 0.3) {isMuon=true; break;}
				  }
			      }
			  }
			if(isMuon) continue;

	
			if( ev.TIV_lead(tl)==1 && ev.TIV_pt(tl) > TIV_pt_l_thr  )
			{ 
				ILV_isoPT = 0.;
				for(int ts = tl+1; ts< ev.TIV_N() && ev.TIV_lead(ts) !=1 ;ts++ )
				{
					
					if( ev.TIV_dR(ts) < TIV_dR_outer_thr  && ev.TIV_dR(ts) > TIV_dR_inner_thr && ev.TIV_pt(ts) > TIV_pt_s_thr )
					{
						ILV_isoPT+= ev.TIV_pt(ts);
					}
				}
				if( ILV_isoPT / ev.TIV_pt(tl) < Lower_TIV ) Lower_TIV = ILV_isoPT / ev.TIV_pt(tl);
			}
		}
		//LowTIV = Lower_TIV;
	


		if ( ev.LowTIV()  > mCut )
		//if ( LowTIV  > mCut )
		{
			return true;
		} 
		else
		{
		    return false;
		}
	}
	std::ostream& CutTIV::Description(std::ostream &ostrm) 
	{
		ostrm << "  TIV Cut" << "  TIV>" << mCut << " :.................";
		return ostrm;
	}
		

///--------------------------GenPar Selection---------------------------------------------------------------------

        GenParExist::GenParExist(int pdgId) : mPdgId(pdgId){} 
	GenParExist::~GenParExist() {}

	bool GenParExist::Process(EventData & ev) 
	{
		bool send = false; 
		for(int i=0; i<ev.NGenPar(); i++)
		{
			if(abs(ev.GenParId(i) )==mPdgId && ev.GenParStatus(i)==3 )
			{
				
				send=true;
			}
		}

		return send;
	}
	std::ostream& GenParExist::Description(std::ostream &ostrm) 
	{
		ostrm << "  Gen PdgID:" << mPdgId << " Exist  :.................";
		return ostrm;
	} 
///---------------------------- W +/- Selection------------------------------------------------------------------

	WsignSelection::WsignSelection(double charge) : mCharge(charge){} 
	WsignSelection::~WsignSelection() {}

	bool WsignSelection::Process(EventData & ev) 
	{
		bool send = false; 

		int t = ev.MetType();

		int IsoLepIndex=0; 
		int LepCharge=0;

		for(int i=0; i<ev.NPFLep(); i++ )
		{
			if( PFLepTightCuts(ev ,i) )
			{
				IsoLepIndex++;
				LepCharge = ev.PFLepCharge(i);
			}
		}
		
		if(IsoLepIndex==1)
		{
			double WmunuMT=0;
			double MTPt=0;

			for(int i=0; i<ev.NPFLep(); i++ )
			{
				if( PFLepTightCuts(ev ,i) )
				{  
					double MTEn= ev.PFLepPt(i)+ ev.MetPt(t);
					double MTPx= ev.PFLepPx(i)+ ev.MetPx(t);
					double MTPy= ev.PFLepPy(i)+ ev.MetPy(t);
					//double MTPz= ev.PFMuonPz(i);

					MTPt=sqrt(MTPx*MTPx+MTPy*MTPy);
					WmunuMT=sqrt((MTEn*MTEn)-(MTPt*MTPt));	
				}	
			} 

			if( WmunuMT>50. && WmunuMT<100. && LepCharge == mCharge ) send =true;

			//if( WmunuMT>50. && WmunuMT<100. ) send =true;
		}
				
		
		return send;

	}
	std::ostream& WsignSelection::Description(std::ostream &ostrm) 
	{
		ostrm << "  W Selection  Sign:" << mCharge << " :.................";
		return ostrm;
	}
///---------------------------- Z Selection------------------------------------------------------------------

	ZSelection::ZSelection(double charge) : mCharge(charge){} 
	ZSelection::~ZSelection() {}

	bool ZSelection::Process(EventData & ev) 
	{
		bool send = false; 

		//int t = ev.MetType();

		int IsoLepIndex=0; 
		//int  LepCharge=0;

		int isoLepPseq[20], isoLepMseq[20], isoLepPnum=0,isoLepMnum=0; //=0 for isoMuPnum,isoMuMnum

		for (int i=0; i<20; i++)
		{
			isoLepPseq[i]=0; isoLepMseq[i]=0;
		}

		for(int i=0; i<ev.NPFLep(); i++ )
		{
			if( PFLepTightCuts(ev ,i) )
			{
				IsoLepIndex++;
				//LepCharge = ev.PFLepCharge(i);

				if(ev.PFLepCharge(i)<0)
				{
					isoLepMseq[isoLepMnum]=i;
					isoLepMnum++;
				}
				else if(ev.PFLepCharge(i)>0)
				{
					isoLepPseq[isoLepPnum]=i;
					isoLepPnum++;
				}
			}
		}

		if( isoLepPnum==1 && isoLepMnum==1)
		{

		        //double dimuPhi =0;
			double ZmumuMT=0;
			double ZPt=0;
	
			for(int i=0; i<isoLepMnum ; i++ )
			{
				int ixmum=isoLepMseq[i];
	
				for(int j=0; j<isoLepPnum ; j++ )
				{
					int ixmup=isoLepPseq[j] ;
		
					double ZEn= ev.PFLepE(ixmup)  + ev.PFLepE(ixmum) ;
					double ZPx= ev.PFLepPx(ixmup) + ev.PFLepPx(ixmum);
					double ZPy= ev.PFLepPy(ixmup) + ev.PFLepPy(ixmum);
					double ZPz= ev.PFLepPz(ixmup) + ev.PFLepPz(ixmum);
		
					ZPt=sqrt(ZPx*ZPx + ZPy*ZPy);
		
					ZmumuMT=sqrt((ZEn*ZEn)-(ZPt*ZPt)-(ZPz*ZPz));
		
					//dimuPhi = atan2( ZPy, ZPx);
				}
			}
	
			if( ZmumuMT>60 && ZmumuMT<120 ) send =true;
			//if( ZmumuMT>0 && ZmumuMT<12000 ) send =true;

		}


		return send;

	}
	std::ostream& ZSelection::Description(std::ostream &ostrm) 
	{
		ostrm << "  Z Selection  Sign:" << mCharge << " :.................";
		return ostrm;
	}


///---------------------------PF Lep Iso--------------------------------------------------

	PFLepIso::PFLepIso(double cut) :mCut(cut) {} 
	PFLepIso::~PFLepIso() {}

	bool PFLepIso::Process(EventData & ev) 
	{
		bool send = false; 

		
		for(int i=0; i<ev.NPFLep(); i++ )
		{
			if(  PFLepTightCuts(ev , i, mCut)  ) send =true ;

		}


		return send;
	}
	std::ostream& PFLepIso::Description(std::ostream &ostrm) 
	{
		ostrm << "  PF Lepton Iso:"  << " :.................";
		return ostrm;
	}


///--------------------------No PF  Muon for monojet -----------------------------------------------


	NoPFMuon::NoPFMuon(double pt) : mPt(pt) {} 
	NoPFMuon::~NoPFMuon() {}

	bool NoPFMuon::Process(EventData & ev) 
	{
		bool  send=true;

		for(int i=0; i<ev.NPFMuon(); i++ )
		{
			if(  PFMuonTightCuts(ev , i,  mPt) == true ) send =false ;

		}

		/*for(int i=0; i<ev.NGenPar(); i++)
		{
			if( (abs(ev.GenParId(i) )==12 || abs(ev.GenParId(i) )==14 || abs(ev.GenParId(i) )==16 ) && ev.GenParStatus(i)==3 )
			{
				if(ev.GenParPt(i) <20. || abs(ev.GenParEta(i))>2.1  ) send=false;
			}
		}*/
			

		return send;
	}
	std::ostream& NoPFMuon::Description(std::ostream &ostrm) 
	{
		ostrm << "  No PFMuon   pt>" <<  mPt << " GeV :............";
		return ostrm;
	}

///--------------------------No PF  Electron for monojet ------------------------------------------


	NoPFElec::NoPFElec(double pt) : mPt(pt) {} 
	NoPFElec::~NoPFElec() {}

	bool NoPFElec::Process(EventData & ev) 
	{
		bool  send=true;

		for(int i=0; i<ev.NPFElec(); i++ )
		{
			if(  PFElecTightCuts(ev , i,  mPt) == true ) send =false ;

		}

		return send;
	}
	std::ostream& NoPFElec::Description(std::ostream &ostrm) 
	{
		ostrm << "  No PFElectron   pt>" <<  mPt << " GeV :............";
		return ostrm;
	}		



}
