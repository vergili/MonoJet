#ifndef EventData_h
#define EventData_h

#include <TROOT.h>
#include <TTree.h>
#include <TFile.h>
#include <map>

#include "/uscmst1/prod/sw/cms/slc5_amd64_gcc434/external/lhapdf/5.8.5-cms2/include/LHAPDF/LHAPDF.h"


#define TIVMAX 10000
#define MAXMUON 30
#define MAXTAU 50
#define MAXELEC 30
#define MAXJET 30
#define MAXPHOT 30
#define MAXGENPAR 1500


using namespace std;
class EventData 
{
	public:
		EventData(const string & fileName, UInt_t maxEvents, int isMC);
		~EventData();

	public:
		// Name of dataset
		const std::string & DataSet();
		const std::string mDataSet;

		bool GetNextEvent();
		
		vector<double> PileUpWeights();

		double  Weight();
		int   IsMC();

		string JetType();
		string LepType();
		int    MetType();
		float  EnergyScale();
		float  SecJetCut();
		
		Double_t       PDFWeights(UInt_t id);
		Double_t       PDFWeight(UInt_t id);
		Double_t       PDFWeightAlphaS( UInt_t id );
		Double_t       PDFWeightAlphaSmstw(UInt_t id );
		
		Int_t           run();
		Long64_t        event();
		Int_t           lumi();
		Int_t           bx();
		Int_t           npvm1();
		Int_t           npv0();
		Int_t           npvp1();
		Double_t        ptHat();
		Int_t           NoiseFlag(UInt_t id);

		Int_t           NCaloAK5Jets();
		Double_t        CaloAK5JetE(UInt_t id);    
		Double_t        CaloAK5JetPt(UInt_t id);    
		Double_t        CaloAK5JetPx(UInt_t id);    
		Double_t        CaloAK5JetPy(UInt_t id);    
		Double_t        CaloAK5JetPz(UInt_t id);    
		Double_t        CaloAK5JetEta(UInt_t id);    
		Double_t        CaloAK5JetPhi(UInt_t id);    
		Double_t        CaloAK5JetEmf(UInt_t id);    
		Double_t        CaloAK5JetfHPD(UInt_t id);    
		Double_t        CaloAK5JetfRBX(UInt_t id);    
		Double_t        CaloAK5JetN90Hits(UInt_t id);    
		Int_t           CaloAK5JetN90(UInt_t id);    
		Double_t        CaloAK5JetSigEta(UInt_t id);    
		Double_t        CaloAK5JetSigPhi(UInt_t id);    
		Double_t        CaloAK5JetIDEmf(UInt_t id);    
		Double_t        CaloAK5JetECor(UInt_t id);    
		Double_t        CaloAK5JetPtCor(UInt_t id);    
		Double_t        CaloAK5JetPxCor(UInt_t id);    
		Double_t        CaloAK5JetPyCor(UInt_t id);    
		Double_t        CaloAK5JetPzCor(UInt_t id);    
		Double_t        CaloAK5JetBtagTkCountHighEff(UInt_t id);    
		Double_t        CaloAK5JetBTagSimpleSecVtx(UInt_t id);    
		Double_t        CaloAK5JetBTagCombSecVtx(UInt_t id);    
		Double_t        CaloAK5TrackPt(UInt_t id);    
		Int_t           CaloAK5JetIDLOOSE(UInt_t id);    
		Int_t           CaloAK5JetIDTIGHT(UInt_t id);    


		Int_t           NPFAK5Jets();
		Double_t        PFAK5JetE(UInt_t id);    
		Double_t        PFAK5JetPt(UInt_t id);    
		Double_t        PFAK5JetPx(UInt_t id);    
		Double_t        PFAK5JetPy(UInt_t id);    
		Double_t        PFAK5JetPz(UInt_t id);    
		Double_t        PFAK5JetEta(UInt_t id);    
		Double_t        PFAK5JetPhi(UInt_t id);    
		Double_t        PFAK5JetfHPD(UInt_t id);    
		Double_t        PFAK5JetfRBX(UInt_t id);    
		Double_t        PFAK5JetN90Hits(UInt_t id);    
		Int_t           PFAK5JetN90(UInt_t id);    
		Double_t        PFAK5JetSigEta(UInt_t id);    
		Double_t        PFAK5JetSigPhi(UInt_t id);    
		Double_t        PFAK5JetIDEmf(UInt_t id);    
		Double_t        PFAK5JetECor(UInt_t id);    
		Double_t        PFAK5JetPtCor(UInt_t id);    
		Double_t        PFAK5JetPxCor(UInt_t id);    
		Double_t        PFAK5JetPyCor(UInt_t id);    
		Double_t        PFAK5JetPzCor(UInt_t id);    
		Double_t        PFAK5JetBtagTkCountHighEff(UInt_t id);    
		Double_t        PFAK5JetBTagSimpleSecVtx(UInt_t id);    
		Double_t        PFAK5JetBTagCombSecVtx(UInt_t id);    
		Double_t        PFAK5JetNeuEmEngFrac(UInt_t id);    
		Double_t        PFAK5JetChaEmEngFrac(UInt_t id);    
		Double_t        PFAK5JetChaHadEngFrac(UInt_t id);    
		Double_t        PFAK5JetNeuHadEngFrac(UInt_t id);    
		Double_t        PFAK5JetChaMuEng(UInt_t id);    
		Double_t        PFAK5JetMuonEng(UInt_t id);    
		Double_t        PFAK5JetPhotEng(UInt_t id);    
		Double_t        PFAK5JetElecEng(UInt_t id);    
		Int_t           PFAK5JetNumOfChaMu(UInt_t id);    
		Int_t           PFAK5JetNumOfMuon(UInt_t id);    
		Int_t           PFAK5JetNumOfPhot(UInt_t id);    
		Int_t           PFAK5JetNumOfElec(UInt_t id);    
		Int_t           PFAK5JetNumOfNeu(UInt_t id);    
		Int_t           PFAK5JetNumOfCha(UInt_t id);    
		Int_t           PFAK5JetNumOfNeuHad(UInt_t id);    
		Int_t           PFAK5JetNumOfChaHad(UInt_t id);    
		Int_t           PFAK5JetNumOfDaughters(UInt_t id);    
		Int_t           PFAK5JetIDLOOSE(UInt_t id);    
		Int_t           PFAK5JetIDTIGHT(UInt_t id);    
		Double_t        PFAK5uncer(UInt_t id);


		Int_t           NMet();
		Double_t        MetPt(UInt_t id);
		Double_t        MetPx(UInt_t id);
		Double_t        MetPy(UInt_t id);
		Double_t        MetPhi(UInt_t id);
		Double_t        MetSumEt(UInt_t id);
		Double_t        MetSign(UInt_t id);

		Int_t   		NPFLep();
		Double_t		PFLepPt(UInt_t id);
		Double_t		PFLepE(UInt_t id);
		Double_t		PFLepPx(UInt_t id);
		Double_t		PFLepPy(UInt_t id);
		Double_t		PFLepPz(UInt_t id);
		Double_t		PFLepEta(UInt_t id);
		Double_t		PFLepPhi(UInt_t id);
		Int_t   		PFLepCharge(UInt_t id);

		Int_t           NMuon();
		Double_t        MuonPt(UInt_t id);    
		Double_t        MuonEt(UInt_t id);    
		Double_t        MuonE(UInt_t id);    
		Double_t        MuonPx(UInt_t id);    
		Double_t        MuonPy(UInt_t id);    
		Double_t        MuonPz(UInt_t id);    
		Double_t        MuonEta(UInt_t id);    
		Double_t        MuonPhi(UInt_t id);    
		Double_t        MuonCharge(UInt_t id);    
		Int_t           MuonIsGlobal(UInt_t id);    
		Int_t           MuonIsStandAlone(UInt_t id);    
		Int_t           MuonIsTracker(UInt_t id);    
		Double_t        MuonSumPtDR03(UInt_t id);    
		Double_t        MuonSumPtDR05(UInt_t id);    
		Double_t        MuonEmEtDR03(UInt_t id);    
		Double_t        MuonHadEtDR03(UInt_t id);    
		Int_t           MuonNumOfMatches(UInt_t id);    
		Double_t        MuonCombChi2Norm(UInt_t id);    
		Int_t           MuonCombValidHits(UInt_t id);    
		Int_t           MuonCombLostHits(UInt_t id);    
		Double_t        MuonCombPt(UInt_t id);    
		Double_t        MuonCombPz(UInt_t id);    
		Double_t        MuonCombP(UInt_t id);    
		Double_t        MuonCombEta(UInt_t id);    
		Double_t        MuonCombPhi(UInt_t id);    
		Double_t        MuonCombChi2(UInt_t id);    
		Double_t        MuonCombCharge(UInt_t id);    
		Double_t        MuonCombQOverPError(UInt_t id);    
		Double_t        MuonCombNdof(UInt_t id);    
		Double_t        MuonCombVx(UInt_t id);    
		Double_t        MuonCombVy(UInt_t id);    
		Double_t        MuonCombVz(UInt_t id);    
		Double_t        MuonCombD0(UInt_t id);    
		Double_t        MuonCombDz(UInt_t id);    
		Double_t        MuonStandChi2Norm(UInt_t id);    
		Int_t           MuonStandValidHits(UInt_t id);    
		Int_t           MuonStandLostHits(UInt_t id);    
		Double_t        MuonStandPt(UInt_t id);    
		Double_t        MuonStandPz(UInt_t id);    
		Double_t        MuonStandP(UInt_t id);    
		Double_t        MuonStandEta(UInt_t id);    
		Double_t        MuonStandPhi(UInt_t id);    
		Double_t        MuonStandChi2(UInt_t id);    
		Double_t        MuonStandCharge(UInt_t id);    
		Double_t        MuonStandQOverPError(UInt_t id);    
		Double_t        MuonTrkChi2Norm(UInt_t id);    
		Int_t           MuonTrkValidHits(UInt_t id);    
		Int_t           MuonTrkLostHits(UInt_t id);    
		Double_t        MuonTrkPt(UInt_t id);    
		Double_t        MuonTrkPz(UInt_t id);    
		Double_t        MuonTrkP(UInt_t id);    
		Double_t        MuonTrkEta(UInt_t id);    
		Double_t        MuonTrkPhi(UInt_t id);    
		Double_t        MuonTrkChi2(UInt_t id);    
		Double_t        MuonTrkCharge(UInt_t id);    
		Double_t        MuonTrkQOverPError(UInt_t id);    
		Double_t        MuonTrkDxy(UInt_t id);    
		Int_t           MuonTrkNumOfValidPixHits(UInt_t id);    

		Int_t           NPFMuon();
		Double_t        PFMuonPt(UInt_t id);    
		Double_t        PFMuonEt(UInt_t id);    
		Double_t        PFMuonE(UInt_t id);    
		Double_t        PFMuonPx(UInt_t id);    
		Double_t        PFMuonPy(UInt_t id);
		Double_t        PFMuonPz(UInt_t id);
		Double_t        PFMuonEta(UInt_t id);
		Double_t        PFMuonPhi(UInt_t id);
		Int_t           PFMuonCharge(UInt_t id);    
		Int_t           PFMuonIsGlobal(UInt_t id);    
		Int_t           PFMuonIsStandAlone(UInt_t id);    
		Int_t           PFMuonIsTracker(UInt_t id);    
		Double_t        PFMuonChargedHadronIso(UInt_t id);    
		Double_t        PFMuonPhotonIso(UInt_t id);    
		Double_t        PFMuonNeutralHadronIso(UInt_t id);    
		Int_t           PFMuonisGMPT(UInt_t id);    
		Int_t           PFMuonNumOfMatches(UInt_t id);    
		Double_t        PFMuoninnertrackPt(UInt_t id);    
		Int_t           PFMuonnValidHits(UInt_t id);    
		Int_t           PFMuonnValidPixelHits(UInt_t id);    
		Double_t        PFMuondxy(UInt_t id);    
		Double_t        PFMuondz(UInt_t id);    
		Double_t        PFMuonCombChi2Norm(UInt_t id);    
		Int_t           PFMuonCombValidHits(UInt_t id);    
		Int_t           PFMuonCombLostHits(UInt_t id);    
		Double_t        PFMuonCombPt(UInt_t id);    
		Double_t        PFMuonCombPz(UInt_t id);    
		Double_t        PFMuonCombP(UInt_t id);    
		Double_t        PFMuonCombEta(UInt_t id);    
		Double_t        PFMuonCombPhi(UInt_t id);    
		Double_t        PFMuonCombChi2(UInt_t id);    
		Double_t        PFMuonCombCharge(UInt_t id);    
		Double_t        PFMuonCombQOverPError(UInt_t id);    
		Double_t        PFMuonCombNdof(UInt_t id);    
		Double_t        PFMuonCombVx(UInt_t id);    
		Double_t        PFMuonCombVy(UInt_t id);    
		Double_t        PFMuonCombVz(UInt_t id);    
		Double_t        PFMuonCombD0(UInt_t id);    
		Double_t        PFMuonCombDz(UInt_t id);    
		Double_t        PFMuonStandChi2Norm(UInt_t id);    
		Int_t           PFMuonStandValidHits(UInt_t id);    
		Int_t           PFMuonStandLostHits(UInt_t id);    
		Double_t        PFMuonStandPt(UInt_t id);    
		Double_t        PFMuonStandPz(UInt_t id);    
		Double_t        PFMuonStandP(UInt_t id);    
		Double_t        PFMuonStandEta(UInt_t id);    
		Double_t        PFMuonStandPhi(UInt_t id);    
		Double_t        PFMuonStandChi2(UInt_t id);    
		Double_t        PFMuonStandCharge(UInt_t id);    
		Double_t        PFMuonStandQOverPError(UInt_t id);    
		Double_t        PFMuonTrkChi2Norm(UInt_t id);    
		Int_t           PFMuonTrkValidHits(UInt_t id);    
		Int_t           PFMuonTrkLostHits(UInt_t id);    
		Double_t        PFMuonTrkPt(UInt_t id);    
		Double_t        PFMuonTrkPz(UInt_t id);    
		Double_t        PFMuonTrkP(UInt_t id);    
		Double_t        PFMuonTrkEta(UInt_t id);    
		Double_t        PFMuonTrkPhi(UInt_t id);    
		Double_t        PFMuonTrkChi2(UInt_t id);    
		Double_t        PFMuonTrkCharge(UInt_t id);    
		Double_t        PFMuonTrkQOverPError(UInt_t id);    
		Double_t        PFMuonTrkDxy(UInt_t id);    
		Double_t        PFMuonTrkNumOfValidPixHits(UInt_t id);   
 
		Int_t           NElec();
		Double_t        ElecE(UInt_t id);    
		Double_t        ElecPt(UInt_t id);    
		Double_t        ElecPx(UInt_t id);    
		Double_t        ElecPy(UInt_t id);    
		Double_t        ElecPz(UInt_t id);    
		Int_t           ElecEcalseed(UInt_t id);    
		Int_t           ElecID80(UInt_t id);    
		Int_t           ElecID95(UInt_t id);    
		Double_t        ElecEta(UInt_t id);    
		Double_t        ElecPhi(UInt_t id);    
		Int_t           ElecCharge(UInt_t id);    
		Double_t        Elecdr03HcalTowerSumEt(UInt_t id);    
		Double_t        Elecdr03EcalRecHitSumEt(UInt_t id);    
		Double_t        Elecdr03TkSumPt(UInt_t id);    
		Int_t           ElecNumOfValidHits(UInt_t id);    
		Int_t           ElecInnerNumOfHits(UInt_t id);    
		Double_t        Elecdist(UInt_t id);    
		Double_t        Elecdcot(UInt_t id);    
		Double_t        ElecNormChi2(UInt_t id);    
		Double_t        Elecdxy(UInt_t id);    
		Double_t        Elecdz(UInt_t id);    
		Int_t           ElecdB(UInt_t id);    
		Int_t           ElecIsEB(UInt_t id);    
		Double_t        Elecfbrem(UInt_t id);    
		Double_t        ElecDEtaSuTrAtVtx(UInt_t id);    
		Double_t        ElecDPhiSuTrAtVtx(UInt_t id);    
		Double_t        ElecHadronicOverEm(UInt_t id);    
		Double_t        ElecHcalOverEcal(UInt_t id);    
		Double_t        ElecSuperClusOverP(UInt_t id);    
		Double_t        Elecetaeta(UInt_t id);    
		Double_t        Elecietaieta(UInt_t id);    

		Int_t           NPFElec();
		Int_t           PFElecCharge(UInt_t id);    
		Int_t           PFElecIsEB(UInt_t id);    
		Double_t        PFElecPassTight(UInt_t id);    
		Double_t        PFElecE(UInt_t id);    
		Double_t        PFElecPt(UInt_t id);    
		Double_t        PFElecPx(UInt_t id);    
		Double_t        PFElecPy(UInt_t id);    
		Double_t        PFElecPz(UInt_t id);    
		Double_t        PFElecEta(UInt_t id);    
		Double_t        PFElecPhi(UInt_t id);    
		Double_t        PFElecCharHadIso(UInt_t id);    
		Double_t        PFElecPhoIso(UInt_t id);    
		Double_t        PFElecNeuHadIso(UInt_t id);    
		Double_t        PFElecMva(UInt_t id);    
		Double_t        PFElecdxy(UInt_t id);    
		Double_t        PFElecdz(UInt_t id);    
		Double_t        PFElecHadOverEm(UInt_t id);    
		Double_t        PFElecHcalOverEm(UInt_t id);    
		Double_t        PFElecSupClusOverP(UInt_t id);    
		Double_t        PFElecInnerHits(UInt_t id);    
		Double_t        PFElecConvDist(UInt_t id);    
		Double_t        PFElecConvDcot(UInt_t id);    
		Double_t        PFElecDEtaSuTrAtVtx(UInt_t id);    
		Double_t        PFElecDPhiSuTrAtVtx(UInt_t id);    
		Double_t        PFElecHadronicOverEm(UInt_t id);    
		Double_t        PFElecHcalOverEcal(UInt_t id);    
		Double_t        PFElecetaeta(UInt_t id);    
		Double_t        PFElecietaieta(UInt_t id);    


		Int_t           NTau();
		Double_t        TauE(UInt_t id);    
		Double_t        TauPt(UInt_t id);    
		Double_t        TauPx(UInt_t id);    
		Double_t        TauPy(UInt_t id);    
		Double_t        TauPz(UInt_t id);    
		Double_t        TauEta(UInt_t id);    
		Double_t        TauPhi(UInt_t id);    
		Double_t        TauEtaEtaMoment(UInt_t id);    
		Double_t        TauPhiPhiMoment(UInt_t id);    
		Double_t        TauEtaPhiMoment(UInt_t id);    
		Double_t        TauTracksInvariantMass(UInt_t id);    
		Double_t        TauSignalTracksInvariantMass(UInt_t id);    
		Double_t        TauMaximumHCALhitEt(UInt_t id);    
		Double_t        TauIsolationECALhitsEtSum(UInt_t id);    
		Double_t        TauIsolationTracksPtSum(UInt_t id);    
		Double_t        TauLeadTrackHCAL3x3hottesthitDEta(UInt_t id);    
		Double_t        TauLeadTrackHCAL3x3hitsEtSum(UInt_t id);    
		Double_t        TauLeadTracksignedSipt(UInt_t id);    

		Int_t           NPFTau();
		Double_t        PFTauE(UInt_t id);    
		Double_t        PFTauPt(UInt_t id);    
		Double_t        PFTauPx(UInt_t id);    
		Double_t        PFTauPy(UInt_t id);    
		Double_t        PFTauPz(UInt_t id);    
		Double_t        PFTauEta(UInt_t id);    
		Double_t        PFTauPhi(UInt_t id);    
		Int_t           PFTauCharge(UInt_t id);    
		Double_t        PFTauEtaEtaMoment(UInt_t id);    
		Double_t        PFTauPhiPhiMoment(UInt_t id);    
		Double_t        PFTauEtaPhiMoment(UInt_t id);    
		Double_t        PFTauLeadPFChargedHadrCandsignedSipt(UInt_t id);    
		Double_t        PFTauIsoPFChargedHadrCandsPtSum(UInt_t id);    
		Double_t        PFTauIsoPFGammaCandsEtSum(UInt_t id);    
		Double_t        PFTauMaximumHCALPFClusterEt(UInt_t id);    
		Double_t        PFTauEmFraction(UInt_t id);    
		Double_t        PFTauHcalTotOverPLead(UInt_t id);    
		Double_t        PFTauHcalMaxOverPLead(UInt_t id);    
		Double_t        PFTauHcal3x3OverPLead(UInt_t id);    
		Double_t        PFTauEcalStripSumEOverPLead(UInt_t id);    
		Double_t        PFTauBremsRecoveryEOverPLead(UInt_t id);    
		Double_t        PFTauElectronPreIDOutput(UInt_t id);    
		Double_t        PFTauElectronPreIDDecision(UInt_t id);    
		Double_t        PFTauCaloComp(UInt_t id);    
		Double_t        PFTauSegComp(UInt_t id);    
		Double_t        PFTauMuonDecision(UInt_t id);    

		Double_t        PFTauLeadTrackPtCut(UInt_t id); 
		Double_t        PFTauByIso(UInt_t id);    
		Double_t        PFTauByTaNCfrHalfPercent(UInt_t id);    


		Int_t           NPhot();
		Double_t        PhotE(UInt_t id);    
		Double_t        PhotPt(UInt_t id);    
		Double_t        PhotPx(UInt_t id);    
		Double_t        PhotPy(UInt_t id);    
		Double_t        PhotPz(UInt_t id);    
		Double_t        PhotEta(UInt_t id);    
		Double_t        PhotPhi(UInt_t id);    
		Double_t        PhotE1x5(UInt_t id);    
		Double_t        PhotE2x5(UInt_t id);    
		Double_t        PhotE5x5(UInt_t id);    
		Double_t        PhotSigEta(UInt_t id);    
		Double_t        PhotSigPhi(UInt_t id);    
		Double_t        PhotEcalIso04(UInt_t id);    
		Double_t        PhotHcalIso04(UInt_t id);    
		Double_t        PhotTrackIso04(UInt_t id);    
		Double_t        PhotHasPixSeed(UInt_t id);    
		Double_t        PhotIsPhot(UInt_t id);    

		Int_t           NPV();
		Double_t        PVx(UInt_t id);    
		Double_t        PVy(UInt_t id);    
		Double_t        PVz(UInt_t id);    
		Double_t        PVchi2(UInt_t id);    
		Double_t        PVndof(UInt_t id);    
		Int_t           PVntracks(UInt_t id);    

		Int_t           nHLT();
		Int_t           HLTArray(UInt_t id);   
		Int_t           HLTArray2(UInt_t id);
		string          HLTNames();
		Int_t           HLTPreScale2(UInt_t id);
		Int_t           nL1();
		Int_t           L1Array(UInt_t id);   
		Int_t           nL1T();
		Int_t           L1TArray(UInt_t id);   

		Int_t           BeamHaloTight();
		Int_t           BeamHaloLoose();

		Int_t			TIV_N();
		Float_t         TIV(UInt_t id);    
		Float_t         TIV_pt(UInt_t id);    
		Float_t         TIV_px(UInt_t id);    
		Float_t         TIV_py(UInt_t id);    
		Float_t         TIV_pz(UInt_t id);    
		Float_t         TIV_phi(UInt_t id);    
		Float_t         TIV_eta(UInt_t id);    
		Float_t         TIV_dsz(UInt_t id);    
		Float_t         TIV_dxy(UInt_t id);    
		Float_t         TIV_d0(UInt_t id);    
		Float_t         TIV_dz(UInt_t id);    
		Float_t         TIV_dsz_corr(UInt_t id);    
		Float_t         TIV_dxy_corr(UInt_t id);    
		Float_t         TIV_d0_corr(UInt_t id);    
		Float_t         TIV_dz_corr(UInt_t id);    
		Float_t         TIV_dR(UInt_t id);    
		Int_t           TIV_lead(UInt_t id);    
		Float_t         LowTIV();

		
		Int_t         NGenPar();
		Int_t         GenParId    (UInt_t id);
		Int_t         GenParStatus(UInt_t id);
		Double_t      GenParE     (UInt_t id); 
		Double_t      GenParPx    (UInt_t id);
		Double_t      GenParPy    (UInt_t id); 
		Double_t      GenParPz    (UInt_t id);
		Double_t      GenParEta   (UInt_t id); 
		Double_t      GenParPhi   (UInt_t id);
		Int_t         GenParCharge(UInt_t id); 
		Double_t      GenParPt    (UInt_t id);
		Double_t      GenParMass  (UInt_t id); 
		Int_t         GenParMother1  (UInt_t id); 
		Int_t         GenParMother2  (UInt_t id); 
                Int_t         GenParDoughterOf(UInt_t id);




		Double_t      GenAK5JetE         (UInt_t id);
		Double_t      GenAK5JetPt        (UInt_t id);
		Double_t      GenAK5JetPx        (UInt_t id);
		Double_t      GenAK5JetPy        (UInt_t id);
		Double_t      GenAK5JetPz        (UInt_t id);
		Double_t      GenAK5JetEta       (UInt_t id);
		Double_t      GenAK5JetPhi       (UInt_t id);
		Double_t      GenAK5JetEmEnergy  (UInt_t id);
		Double_t      GenAK5JetHadEnergy (UInt_t id);

		Double_t	  PDFGenScale();
		Double_t	  PDFx1();
		Double_t	  PDFx2();
		Int_t	      PDFf1();
		Int_t	      PDFf2();
		Double_t	  PDFscale();
		Double_t	  PDFpdf1();
		Double_t	  PDFpdf2();


	private:

		unsigned int mEvent, mMaxEvents;

		TFile *mFile;
		TTree *mDataTree;
		

		map<string, string> mydataset;
		map<string, double> mylumi;

		// TTree variable
		vector<double>  mPileUpWeights;
		string mFileName; 
		double mWeight;
		int   misMC;

		string mJetType;
		string mLepType;
		int mMetType;
    
		float mEnergyScale;
		float mSecJetCut;

		double mCaloTowerdEx , mCaloTowerdEy; 
	
		Double_t        mPDFWeights[45];

		Int_t           mrun;
		Long64_t        mevent;
		Int_t           mlumi;
		Int_t           mbx;
		Int_t           mnpvm1;
		Int_t           mnpv0;
		Int_t           mnpvp1;

		Double_t        mptHat;
		Int_t           mNoiseFlag[10];

		Int_t           mNCaloAK5Jets;
		Double_t        mCaloAK5JetE[MAXJET];    
		Double_t        mCaloAK5JetPt[MAXJET];    
		Double_t        mCaloAK5JetPx[MAXJET];    
		Double_t        mCaloAK5JetPy[MAXJET];    
		Double_t        mCaloAK5JetPz[MAXJET];    
		Double_t        mCaloAK5JetEta[MAXJET];    
		Double_t        mCaloAK5JetPhi[MAXJET];    
		Double_t        mCaloAK5JetEmf[MAXJET];    
		Double_t        mCaloAK5JetfHPD[MAXJET];    
		Double_t        mCaloAK5JetfRBX[MAXJET];    
		Double_t        mCaloAK5JetN90Hits[MAXJET];    
		Int_t           mCaloAK5JetN90[MAXJET];    
		Double_t        mCaloAK5JetSigEta[MAXJET];    
		Double_t        mCaloAK5JetSigPhi[MAXJET];    
		Double_t        mCaloAK5JetIDEmf[MAXJET];    
		Double_t        mCaloAK5JetECor[MAXJET];    
		Double_t        mCaloAK5JetPtCor[MAXJET];    
		Double_t        mCaloAK5JetPxCor[MAXJET];    
		Double_t        mCaloAK5JetPyCor[MAXJET];    
		Double_t        mCaloAK5JetPzCor[MAXJET];    
		Double_t        mCaloAK5JetBtagTkCountHighEff[MAXJET];    
		Double_t        mCaloAK5JetBTagSimpleSecVtx[MAXJET];    
		Double_t        mCaloAK5JetBTagCombSecVtx[MAXJET];    
		Double_t        mCaloAK5TrackPt[MAXJET];    
		Int_t           mCaloAK5JetIDLOOSE[MAXJET];    
		Int_t           mCaloAK5JetIDTIGHT[MAXJET];    


		Int_t           mNPFAK5Jets;
		Double_t        mPFAK5JetE[MAXJET];    
		Double_t        mPFAK5JetPt[MAXJET];    
		Double_t        mPFAK5JetPx[MAXJET];    
		Double_t        mPFAK5JetPy[MAXJET];    
		Double_t        mPFAK5JetPz[MAXJET];    
		Double_t        mPFAK5JetEta[MAXJET];    
		Double_t        mPFAK5JetPhi[MAXJET];    
		Double_t        mPFAK5JetfHPD[MAXJET];    
		Double_t        mPFAK5JetfRBX[MAXJET];    
		Double_t        mPFAK5JetN90Hits[MAXJET];    
		Int_t           mPFAK5JetN90[MAXJET];    
		Double_t        mPFAK5JetSigEta[MAXJET];    
		Double_t        mPFAK5JetSigPhi[MAXJET];    
		Double_t        mPFAK5JetIDEmf[MAXJET];    
		Double_t        mPFAK5JetECor[MAXJET];    
		Double_t        mPFAK5JetPtCor[MAXJET];    
		Double_t        mPFAK5JetPxCor[MAXJET];    
		Double_t        mPFAK5JetPyCor[MAXJET];    
		Double_t        mPFAK5JetPzCor[MAXJET];    
		Double_t        mPFAK5JetBtagTkCountHighEff[MAXJET];    
		Double_t        mPFAK5JetBTagSimpleSecVtx[MAXJET];    
		Double_t        mPFAK5JetBTagCombSecVtx[MAXJET];    
		Double_t        mPFAK5JetNeuEmEngFrac[MAXJET];    
		Double_t        mPFAK5JetChaEmEngFrac[MAXJET];    
		Double_t        mPFAK5JetChaHadEngFrac[MAXJET];    
		Double_t        mPFAK5JetNeuHadEngFrac[MAXJET];    
		Double_t        mPFAK5JetChaMuEng[MAXJET];    
		Double_t        mPFAK5JetMuonEng[MAXJET];    
		Double_t        mPFAK5JetPhotEng[MAXJET];    
		Double_t        mPFAK5JetElecEng[MAXJET];    
		Int_t           mPFAK5JetNumOfChaMu[MAXJET];    
		Int_t           mPFAK5JetNumOfMuon[MAXJET];    
		Int_t           mPFAK5JetNumOfPhot[MAXJET];    
		Int_t           mPFAK5JetNumOfElec[MAXJET];    
		Int_t           mPFAK5JetNumOfNeu[MAXJET];    
		Int_t           mPFAK5JetNumOfCha[MAXJET];    
		Int_t           mPFAK5JetNumOfNeuHad[MAXJET];    
		Int_t           mPFAK5JetNumOfChaHad[MAXJET];    
		Int_t           mPFAK5JetNumOfDaughters[MAXJET];    
		Int_t           mPFAK5JetIDLOOSE[MAXJET];    
		Int_t           mPFAK5JetIDTIGHT[MAXJET];    
		Double_t        mPFAK5uncer[MAXJET];

		Int_t           mNMet;
		Double_t        mMetPt[30];    
		Double_t        mMetPx[30];    
		Double_t        mMetPy[30];    
		Double_t        mMetPhi[30];    
		Double_t        mMetSumEt[30];    
		Double_t        mMetSign[30];    

		Int_t           mNPFLep;
		Double_t        mPFLepPt[MAXMUON];    
		Double_t        mPFLepE[MAXMUON];    
		Double_t        mPFLepPx[MAXMUON];    
		Double_t        mPFLepPy[MAXMUON];    
		Double_t        mPFLepPz[MAXMUON];    
		Double_t        mPFLepEta[MAXMUON];    
		Double_t        mPFLepPhi[MAXMUON];    
		Int_t           mPFLepCharge[MAXMUON];  

		Int_t           mNMuon;
		Double_t        mMuonPt[MAXMUON];    
		Double_t        mMuonEt[MAXMUON];    
		Double_t        mMuonE[MAXMUON];    
		Double_t        mMuonPx[MAXMUON];    
		Double_t        mMuonPy[MAXMUON];    
		Double_t        mMuonPz[MAXMUON];    
		Double_t        mMuonEta[MAXMUON];    
		Double_t        mMuonPhi[MAXMUON];    
		Double_t        mMuonCharge[MAXMUON];    
		Int_t           mMuonIsGlobal[MAXMUON];    
		Int_t           mMuonIsStandAlone[MAXMUON];    
		Int_t           mMuonIsTracker[MAXMUON];    
		Double_t        mMuonSumPtDR03[MAXMUON];    
		Double_t        mMuonSumPtDR05[MAXMUON];    
		Double_t        mMuonEmEtDR03[MAXMUON];    
		Double_t        mMuonHadEtDR03[MAXMUON];    
		Int_t           mMuonNumOfMatches[MAXMUON];    
		Double_t        mMuonCombChi2Norm[MAXMUON];    
		Int_t           mMuonCombValidHits[MAXMUON];    
		Int_t           mMuonCombLostHits[MAXMUON];    
		Double_t        mMuonCombPt[MAXMUON];    
		Double_t        mMuonCombPz[MAXMUON];    
		Double_t        mMuonCombP[MAXMUON];    
		Double_t        mMuonCombEta[MAXMUON];    
		Double_t        mMuonCombPhi[MAXMUON];    
		Double_t        mMuonCombChi2[MAXMUON];    
		Double_t        mMuonCombCharge[MAXMUON];    
		Double_t        mMuonCombQOverPError[MAXMUON];    
		Double_t        mMuonCombNdof[MAXMUON];    
		Double_t        mMuonCombVx[MAXMUON];    
		Double_t        mMuonCombVy[MAXMUON];    
		Double_t        mMuonCombVz[MAXMUON];    
		Double_t        mMuonCombD0[MAXMUON];    
		Double_t        mMuonCombDz[MAXMUON];    
		Double_t        mMuonStandChi2Norm[MAXMUON];    
		Int_t           mMuonStandValidHits[MAXMUON];    
		Int_t           mMuonStandLostHits[MAXMUON];    
		Double_t        mMuonStandPt[MAXMUON];    
		Double_t        mMuonStandPz[MAXMUON];    
		Double_t        mMuonStandP[MAXMUON];    
		Double_t        mMuonStandEta[MAXMUON];    
		Double_t        mMuonStandPhi[MAXMUON];    
		Double_t        mMuonStandChi2[MAXMUON];    
		Double_t        mMuonStandCharge[MAXMUON];    
		Double_t        mMuonStandQOverPError[MAXMUON];    
		Double_t        mMuonTrkChi2Norm[MAXMUON];    
		Int_t           mMuonTrkValidHits[MAXMUON];    
		Int_t           mMuonTrkLostHits[MAXMUON];    
		Double_t        mMuonTrkPt[MAXMUON];    
		Double_t        mMuonTrkPz[MAXMUON];    
		Double_t        mMuonTrkP[MAXMUON];    
		Double_t        mMuonTrkEta[MAXMUON];    
		Double_t        mMuonTrkPhi[MAXMUON];    
		Double_t        mMuonTrkChi2[MAXMUON];    
		Double_t        mMuonTrkCharge[MAXMUON];    
		Double_t        mMuonTrkQOverPError[MAXMUON];    
		Double_t        mMuonTrkDxy[MAXMUON];    
		Int_t           mMuonTrkNumOfValidPixHits[MAXMUON];    

		Int_t           mNPFMuon;
		Double_t        mPFMuonPt[MAXMUON];    
		Double_t        mPFMuonEt[MAXMUON];    
		Double_t        mPFMuonE[MAXMUON];    
		Double_t        mPFMuonPx[MAXMUON];    
		Double_t        mPFMuonPy[MAXMUON];    
		Double_t        mPFMuonPz[MAXMUON];    
		Double_t        mPFMuonEta[MAXMUON];    
		Double_t        mPFMuonPhi[MAXMUON];    
		Int_t           mPFMuonCharge[MAXMUON];    
		Int_t           mPFMuonIsGlobal[MAXMUON];    
		Int_t           mPFMuonIsStandAlone[MAXMUON];    
		Int_t           mPFMuonIsTracker[MAXMUON];    
		Double_t        mPFMuonChargedHadronIso[MAXMUON];    
		Double_t        mPFMuonPhotonIso[MAXMUON];    
		Double_t        mPFMuonNeutralHadronIso[MAXMUON];    
		Int_t           mPFMuonisGMPT[MAXMUON];    
		Int_t           mPFMuonNumOfMatches[MAXMUON];    
		Double_t        mPFMuoninnertrackPt[MAXMUON];    
		Int_t           mPFMuonnValidHits[MAXMUON];    
		Int_t           mPFMuonnValidPixelHits[MAXMUON];    
		Double_t        mPFMuondxy[MAXMUON];    
		Double_t        mPFMuondz[MAXMUON];    
		Double_t        mPFMuonCombChi2Norm[MAXMUON];    
		Int_t           mPFMuonCombValidHits[MAXMUON];    
		Int_t           mPFMuonCombLostHits[MAXMUON];    
		Double_t        mPFMuonCombPt[MAXMUON];    
		Double_t        mPFMuonCombPz[MAXMUON];    
		Double_t        mPFMuonCombP[MAXMUON];    
		Double_t        mPFMuonCombEta[MAXMUON];    
		Double_t        mPFMuonCombPhi[MAXMUON];    
		Double_t        mPFMuonCombChi2[MAXMUON];    
		Double_t        mPFMuonCombCharge[MAXMUON];    
		Double_t        mPFMuonCombQOverPError[MAXMUON];    
		Double_t        mPFMuonCombNdof[MAXMUON];    
		Double_t        mPFMuonCombVx[MAXMUON];    
		Double_t        mPFMuonCombVy[MAXMUON];    
		Double_t        mPFMuonCombVz[MAXMUON];    
		Double_t        mPFMuonCombD0[MAXMUON];    
		Double_t        mPFMuonCombDz[MAXMUON];    
		Double_t        mPFMuonStandChi2Norm[MAXMUON];    
		Int_t           mPFMuonStandValidHits[MAXMUON];    
		Int_t           mPFMuonStandLostHits[MAXMUON];    
		Double_t        mPFMuonStandPt[MAXMUON];    
		Double_t        mPFMuonStandPz[MAXMUON];    
		Double_t        mPFMuonStandP[MAXMUON];    
		Double_t        mPFMuonStandEta[MAXMUON];    
		Double_t        mPFMuonStandPhi[MAXMUON];    
		Double_t        mPFMuonStandChi2[MAXMUON];    
		Double_t        mPFMuonStandCharge[MAXMUON];    
		Double_t        mPFMuonStandQOverPError[MAXMUON];    
		Double_t        mPFMuonTrkChi2Norm[MAXMUON];    
		Int_t           mPFMuonTrkValidHits[MAXMUON];    
		Int_t           mPFMuonTrkLostHits[MAXMUON];    
		Double_t        mPFMuonTrkPt[MAXMUON];    
		Double_t        mPFMuonTrkPz[MAXMUON];    
		Double_t        mPFMuonTrkP[MAXMUON];    
		Double_t        mPFMuonTrkEta[MAXMUON];    
		Double_t        mPFMuonTrkPhi[MAXMUON];    
		Double_t        mPFMuonTrkChi2[MAXMUON];    
		Double_t        mPFMuonTrkCharge[MAXMUON];    
		Double_t        mPFMuonTrkQOverPError[MAXMUON];    
		Double_t        mPFMuonTrkDxy[MAXMUON];    
		Double_t        mPFMuonTrkNumOfValidPixHits[MAXMUON];   

		Int_t           mNElec;
		Double_t        mElecE[MAXELEC];    
		Double_t        mElecPt[MAXELEC];    
		Double_t        mElecPx[MAXELEC];    
		Double_t        mElecPy[MAXELEC];    
		Double_t        mElecPz[MAXELEC];    
		Int_t           mElecEcalseed[MAXELEC];    
		Int_t           mElecID80[MAXELEC];    
		Int_t           mElecID95[MAXELEC];    
		Double_t        mElecEta[MAXELEC];    
		Double_t        mElecPhi[MAXELEC];    
		Int_t           mElecCharge[MAXELEC];    
		Double_t        mElecdr03HcalTowerSumEt[MAXELEC];    
		Double_t        mElecdr03EcalRecHitSumEt[MAXELEC];    
		Double_t        mElecdr03TkSumPt[MAXELEC];    
		Int_t           mElecNumOfValidHits[MAXELEC];    
		Int_t           mElecInnerNumOfHits[MAXELEC];    
		Double_t        mElecdist[MAXELEC];    
		Double_t        mElecdcot[MAXELEC];    
		Double_t        mElecNormChi2[MAXELEC];    
		Double_t        mElecdxy[MAXELEC];    
		Double_t        mElecdz[MAXELEC];    
		Int_t           mElecdB[MAXELEC];    
		Int_t           mElecIsEB[MAXELEC];    
		Double_t        mElecfbrem[MAXELEC];    
		Double_t        mElecDEtaSuTrAtVtx[MAXELEC];    
		Double_t        mElecDPhiSuTrAtVtx[MAXELEC];    
		Double_t        mElecHadronicOverEm[MAXELEC];    
		Double_t        mElecHcalOverEcal[MAXELEC];    
		Double_t        mElecSuperClusOverP[MAXELEC];    
		Double_t        mElecetaeta[MAXELEC];    
		Double_t        mElecietaieta[MAXELEC];    

		Int_t           mNPFElec;
		Int_t           mPFElecCharge[MAXELEC];    
		Int_t           mPFElecIsEB[MAXELEC];    
		Double_t        mPFElecPassTight[MAXELEC];    
		Double_t        mPFElecE[MAXELEC];    
		Double_t        mPFElecPt[MAXELEC];    
		Double_t        mPFElecPx[MAXELEC];    
		Double_t        mPFElecPy[MAXELEC];    
		Double_t        mPFElecPz[MAXELEC];    
		Double_t        mPFElecEta[MAXELEC];    
		Double_t        mPFElecPhi[MAXELEC];    
		Double_t        mPFElecCharHadIso[MAXELEC];    
		Double_t        mPFElecPhoIso[MAXELEC];    
		Double_t        mPFElecNeuHadIso[MAXELEC];    
		Double_t        mPFElecMva[MAXELEC];    
		Double_t        mPFElecdxy[MAXELEC];    
		Double_t        mPFElecdz[MAXELEC];    
		Double_t        mPFElecHadOverEm[MAXELEC];    
		Double_t        mPFElecHcalOverEm[MAXELEC];    
		Double_t        mPFElecSupClusOverP[MAXELEC];    
		Double_t        mPFElecInnerHits[MAXELEC];    
		Double_t        mPFElecConvDist[MAXELEC];    
		Double_t        mPFElecConvDcot[MAXELEC];    
		Double_t        mPFElecDEtaSuTrAtVtx[MAXELEC];    
		Double_t        mPFElecDPhiSuTrAtVtx[MAXELEC];    
		Double_t        mPFElecHadronicOverEm[MAXELEC];    
		Double_t        mPFElecHcalOverEcal[MAXELEC];    
		Double_t        mPFElecetaeta[MAXELEC];    
		Double_t        mPFElecietaieta[MAXELEC];    

		Int_t           mNTau;
		Double_t        mTauE[MAXTAU];    
		Double_t        mTauPt[MAXTAU];    
		Double_t        mTauPx[MAXTAU];    
		Double_t        mTauPy[MAXTAU];    
		Double_t        mTauPz[MAXTAU];    
		Double_t        mTauEta[MAXTAU];    
		Double_t        mTauPhi[MAXTAU];    
		Double_t        mTauEtaEtaMoment[MAXTAU];    
		Double_t        mTauPhiPhiMoment[MAXTAU];    
		Double_t        mTauEtaPhiMoment[MAXTAU];    
		Double_t        mTauTracksInvariantMass[MAXTAU];    
		Double_t        mTauSignalTracksInvariantMass[MAXTAU];    
		Double_t        mTauMaximumHCALhitEt[MAXTAU];    
		Double_t        mTauIsolationECALhitsEtSum[MAXTAU];    
		Double_t        mTauIsolationTracksPtSum[MAXTAU];    
		Double_t        mTauLeadTrackHCAL3x3hottesthitDEta[MAXTAU];    
		Double_t        mTauLeadTrackHCAL3x3hitsEtSum[MAXTAU];    
		Double_t        mTauLeadTracksignedSipt[MAXTAU];    

		Int_t           mNPFTau;
		Double_t        mPFTauE[MAXTAU];    
		Double_t        mPFTauPt[MAXTAU];    
		Double_t        mPFTauPx[MAXTAU];    
		Double_t        mPFTauPy[MAXTAU];    
		Double_t        mPFTauPz[MAXTAU];    
		Double_t        mPFTauEta[MAXTAU];    
		Double_t        mPFTauPhi[MAXTAU];    
		Int_t           mPFTauCharge[MAXTAU];    
		Double_t        mPFTauEtaEtaMoment[MAXTAU];    
		Double_t        mPFTauPhiPhiMoment[MAXTAU];    
		Double_t        mPFTauEtaPhiMoment[MAXTAU];    
		Double_t        mPFTauLeadPFChargedHadrCandsignedSipt[MAXTAU];    
		Double_t        mPFTauIsoPFChargedHadrCandsPtSum[MAXTAU];    
		Double_t        mPFTauIsoPFGammaCandsEtSum[MAXTAU];    
		Double_t        mPFTauMaximumHCALPFClusterEt[MAXTAU];    
		Double_t        mPFTauEmFraction[MAXTAU];    
		Double_t        mPFTauHcalTotOverPLead[MAXTAU];    
		Double_t        mPFTauHcalMaxOverPLead[MAXTAU];    
		Double_t        mPFTauHcal3x3OverPLead[MAXTAU];    
		Double_t        mPFTauEcalStripSumEOverPLead[MAXTAU];    
		Double_t        mPFTauBremsRecoveryEOverPLead[MAXTAU];    
		Double_t        mPFTauElectronPreIDOutput[MAXTAU];    
		Double_t        mPFTauElectronPreIDDecision[MAXTAU];    
		Double_t        mPFTauCaloComp[MAXTAU];    
		Double_t        mPFTauSegComp[MAXTAU];    
		Double_t        mPFTauMuonDecision[MAXTAU];    

		Double_t        mPFTauLeadTrackPtCut[MAXTAU];    
		Double_t        mPFTauByIso[MAXTAU];    
		Double_t        mPFTauByTaNCfrHalfPercent[MAXTAU];    



		Int_t           mNPhot;
		Double_t        mPhotE[MAXPHOT];    
		Double_t        mPhotPt[MAXPHOT];    
		Double_t        mPhotPx[MAXPHOT];    
		Double_t        mPhotPy[MAXPHOT];    
		Double_t        mPhotPz[MAXPHOT];    
		Double_t        mPhotEta[MAXPHOT];    
		Double_t        mPhotPhi[MAXPHOT];    
		Double_t        mPhotE1x5[MAXPHOT];    
		Double_t        mPhotE2x5[MAXPHOT];    
		Double_t        mPhotE5x5[MAXPHOT];    
		Double_t        mPhotSigEta[MAXPHOT];    
		Double_t        mPhotSigPhi[MAXPHOT];    
		Double_t        mPhotEcalIso04[MAXPHOT];    
		Double_t        mPhotHcalIso04[MAXPHOT];    
		Double_t        mPhotTrackIso04[MAXPHOT];    
		Double_t        mPhotHasPixSeed[MAXPHOT];    
		Double_t        mPhotIsPhot[MAXPHOT];    

		Int_t           mNPV;
		Double_t        mPVx[40];    
		Double_t        mPVy[40];    
		Double_t        mPVz[40];    
		Double_t        mPVchi2[40];    
		Double_t        mPVndof[40];    
		Int_t           mPVntracks[40];    

		Int_t           mnHLT;
		Int_t           mHLTArray[400];   
		Int_t           mHLTArray2[100];
		Char_t          mHLTNames[14000];
		Int_t           mHLTPreScale2[100];
		Int_t           mnL1;
		Int_t           mL1Array[128];   
		Int_t           mnL1T;
		Int_t           mL1TArray[64];   

		Int_t           mBeamHaloTight;
		Int_t           mBeamHaloLoose;

		Int_t           mTIV_N;
		Float_t         mTIV[TIVMAX];    
		Float_t         mTIV_pt[TIVMAX];    
		Float_t         mTIV_px[TIVMAX];    
		Float_t         mTIV_py[TIVMAX];    
		Float_t         mTIV_pz[TIVMAX];    
		Float_t         mTIV_phi[TIVMAX];    
		Float_t         mTIV_eta[TIVMAX];    
		Float_t         mTIV_dsz[TIVMAX];    
		Float_t         mTIV_dxy[TIVMAX];    
		Float_t         mTIV_d0[TIVMAX];    
		Float_t         mTIV_dz[TIVMAX];    
		Float_t         mTIV_dsz_corr[TIVMAX];    
		Float_t         mTIV_dxy_corr[TIVMAX];    
		Float_t         mTIV_d0_corr[TIVMAX];    
		Float_t         mTIV_dz_corr[TIVMAX];    
		Float_t         mTIV_dR[TIVMAX];    
		Int_t           mTIV_lead[TIVMAX];    
		Float_t         mLowTIV;
                  
	
		Int_t           mNGenPar;    
		Int_t           mGenParId[MAXGENPAR];    
		Int_t           mGenParStatus[MAXGENPAR];
		Double_t        mGenParE[MAXGENPAR];     
		Double_t        mGenParPx[MAXGENPAR];    
		Double_t        mGenParPy[MAXGENPAR];    
		Double_t        mGenParPz[MAXGENPAR];    
		Double_t        mGenParEta[MAXGENPAR];   
		Double_t        mGenParPhi[MAXGENPAR];   
		Int_t           mGenParCharge[MAXGENPAR];
		Double_t        mGenParPt[MAXGENPAR];    
		Double_t        mGenParMass[MAXGENPAR];  
		Int_t           mGenParMother1[MAXGENPAR];  
		Int_t           mGenParMother2[MAXGENPAR];  
                Int_t           mGenParDoughterOf[MAXGENPAR];
		



		Double_t        mGenAK5JetE          [MAXJET]; 
		Double_t        mGenAK5JetPt         [MAXJET]; 
		Double_t        mGenAK5JetPx         [MAXJET]; 
		Double_t        mGenAK5JetPy         [MAXJET]; 
		Double_t        mGenAK5JetPz         [MAXJET]; 
		Double_t        mGenAK5JetEta        [MAXJET]; 
		Double_t        mGenAK5JetPhi        [MAXJET]; 
		Double_t        mGenAK5JetEmEnergy   [MAXJET]; 
		Double_t        mGenAK5JetHadEnergy  [MAXJET]; 

		Double_t	  mPDFGenScale;
		Double_t	  mPDFx1;
		Double_t	  mPDFx2;
		Int_t	      mPDFf1;
		Int_t	      mPDFf2;
		Double_t	  mPDFscale;
		Double_t	  mPDFpdf1;
		Double_t	  mPDFpdf2;


                  
                            
};                
                  
#include "EventData.cc"
#endif //~EventDatma_h






