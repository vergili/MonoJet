
rm data_table_*
rm qcd_table_*
rm sint_table_*
rm znunu_table_*

hadd  qcd_table_0.root  qcd*_0.root
hadd  qcd_table_1.root  qcd*_1.root
hadd  qcd_table_2.root  qcd*_2.root
hadd  qcd_table_3.root  qcd*_3.root
hadd  qcd_table_4.root  qcd*_4.root
hadd  qcd_table_5.root  qcd*_5.root
hadd  qcd_table_6.root  qcd*_6.root
hadd  qcd_table_7.root  qcd*_7.root
hadd  qcd_table_8.root  qcd*_8.root
hadd  qcd_table_9.root  qcd*_9.root
hadd  qcd_table_10.root  qcd*_10.root
hadd  qcd_table_11.root  qcd*_11.root
hadd  qcd_table_12.root  qcd*_12.root

hadd  sint_table_0.root  sint*_0.root 
hadd  sint_table_1.root  sint*_1.root 
hadd  sint_table_2.root  sint*_2.root 
hadd  sint_table_3.root  sint*_3.root 
hadd  sint_table_4.root  sint*_4.root 
hadd  sint_table_5.root  sint*_5.root 
hadd  sint_table_6.root  sint*_6.root 
hadd  sint_table_7.root  sint*_7.root 
hadd  sint_table_8.root  sint*_8.root 
hadd  sint_table_9.root  sint*_9.root 
hadd  sint_table_10.root sint*_10.root 
hadd  sint_table_11.root sint*_11.root 
hadd  sint_table_12.root sint*_12.root 


hadd  znunu_table_0.root  znunu*_0.root 
hadd  znunu_table_1.root  znunu*_1.root 
hadd  znunu_table_2.root  znunu*_2.root 
hadd  znunu_table_3.root  znunu*_3.root 
hadd  znunu_table_4.root  znunu*_4.root 
hadd  znunu_table_5.root  znunu*_5.root 
hadd  znunu_table_6.root  znunu*_6.root 
hadd  znunu_table_7.root  znunu*_7.root 
hadd  znunu_table_8.root  znunu*_8.root 
hadd  znunu_table_9.root  znunu*_9.root 
hadd  znunu_table_10.root znunu*_10.root 
hadd  znunu_table_11.root znunu*_11.root 
hadd  znunu_table_12.root znunu*_12.root 



hadd data_table_0.root   met*_AnaMonoJet_0.root     
hadd data_table_1.root   met*_AnaMonoJet_1.root     
hadd data_table_2.root   met*_AnaMonoJet_2.root     
hadd data_table_3.root   met*_AnaMonoJet_3.root     
hadd data_table_4.root   met*_AnaMonoJet_4.root     
hadd data_table_5.root   met*_AnaMonoJet_5.root     
hadd data_table_6.root   met*_AnaMonoJet_6.root     
hadd data_table_7.root   met*_AnaMonoJet_7.root     
hadd data_table_8.root   met*_AnaMonoJet_8.root     
hadd data_table_9.root   met*_AnaMonoJet_9.root     
hadd data_table_10.root  met*_AnaMonoJet_10.root    
hadd data_table_11.root  met*_AnaMonoJet_11.root    
hadd data_table_12.root  met*_AnaMonoJet_12.root    



echo "|   *Selection*       |  *WJets*  |  *Zinv*   |  *ZJets*  |  *TTbar*  |  *SingleT*  | *QCD*  |  *Total Bckg*  |  *Data*  |  *MD2D3*  |   *DM-t*  | "


echo -n "|Pre Selection        " 
Table MetLep1 2.5  wjets_AnaMonoJet_0  znunu_table_0  zjets_AnaMonoJet_0 ttbar_AnaMonoJet_0   sint_table_0  qcd_table_0  data_table_0    md2d3_AnaMonoJet_0    dmavd1_AnaMonoJet_0  
echo " " 
echo -n "|PFMet+mu >200 GeV    " 
Table MetLep1 2.5  wjets_AnaMonoJet_1  znunu_table_1  zjets_AnaMonoJet_1 ttbar_AnaMonoJet_1   sint_table_1  qcd_table_1  data_table_1    md2d3_AnaMonoJet_1    dmavd1_AnaMonoJet_1  
echo " " 
echo -n "|Noise Clean          " 
Table MetLep1 2.5  wjets_AnaMonoJet_2  znunu_table_2  zjets_AnaMonoJet_2 ttbar_AnaMonoJet_2   sint_table_2  qcd_table_2  data_table_2    md2d3_AnaMonoJet_2    dmavd1_AnaMonoJet_2  
echo " " 
echo -n "|Leading Jet Cut      " 
Table MetLep1 2.5  wjets_AnaMonoJet_3  znunu_table_3  zjets_AnaMonoJet_3 ttbar_AnaMonoJet_3   sint_table_3  qcd_table_3  data_table_3    md2d3_AnaMonoJet_3    dmavd1_AnaMonoJet_3  
echo " "
echo -n "|NJet Cut             " 
Table MetLep1 2.5  wjets_AnaMonoJet_4  znunu_table_4  zjets_AnaMonoJet_4 ttbar_AnaMonoJet_4   sint_table_4  qcd_table_4  data_table_4    md2d3_AnaMonoJet_4    dmavd1_AnaMonoJet_4  
echo " "
echo -n "|DPhi(jet1, jet2)<2.5 " 
Table MetLep1 2.5  wjets_AnaMonoJet_5  znunu_table_5  zjets_AnaMonoJet_5 ttbar_AnaMonoJet_5   sint_table_5  qcd_table_5  data_table_5    md2d3_AnaMonoJet_5    dmavd1_AnaMonoJet_5  
echo " "
echo -n "|PF mu pt<10 GeV   " 
Table MetLep1 2.5  wjets_AnaMonoJet_6  znunu_table_6  zjets_AnaMonoJet_6 ttbar_AnaMonoJet_6   sint_table_6  qcd_table_6  data_table_6    md2d3_AnaMonoJet_6    dmavd1_AnaMonoJet_6  
echo " "
echo -n "|PF e  pt<10 GeV   " 
Table MetLep1 2.5  wjets_AnaMonoJet_7  znunu_table_7  zjets_AnaMonoJet_7 ttbar_AnaMonoJet_7   sint_table_7  qcd_table_7  data_table_7    md2d3_AnaMonoJet_7    dmavd1_AnaMonoJet_7  
echo " "
echo -n "|TIV>0.0 1            " 
Table MetLep1 2.5  wjets_AnaMonoJet_8  znunu_table_8  zjets_AnaMonoJet_8 ttbar_AnaMonoJet_8   sint_table_8  qcd_table_8  data_table_8    md2d3_AnaMonoJet_8    dmavd1_AnaMonoJet_8  
echo " "
echo -n "|PFMet+mu >250 GeV    " 
Table MetLep1 2.5  wjets_AnaMonoJet_9  znunu_table_9  zjets_AnaMonoJet_9 ttbar_AnaMonoJet_9   sint_table_9  qcd_table_9  data_table_9    md2d3_AnaMonoJet_9    dmavd1_AnaMonoJet_9  
echo " "
echo -n "|PFMet+mu >300 GeV    " 
Table MetLep1 2.5  wjets_AnaMonoJet_10 znunu_table_10 zjets_AnaMonoJet_10 ttbar_AnaMonoJet_10 sint_table_10 qcd_table_10  data_table_10  md2d3_AnaMonoJet_10   dmavd1_AnaMonoJet_10 
echo " "
echo -n "|PFMet+mu >350 GeV    " 
Table MetLep1 2.5  wjets_AnaMonoJet_11 znunu_table_11 zjets_AnaMonoJet_11 ttbar_AnaMonoJet_11 sint_table_11 qcd_table_11  data_table_11  md2d3_AnaMonoJet_11   dmavd1_AnaMonoJet_11 
echo " "
echo -n "|PFMet+mu >400 GeV    " 
Table MetLep1 2.5  wjets_AnaMonoJet_12 znunu_table_12 zjets_AnaMonoJet_12 ttbar_AnaMonoJet_12 sint_table_12 qcd_table_12  data_table_12  md2d3_AnaMonoJet_12   dmavd1_AnaMonoJet_12 


echo "|     *Wenu*   |"
Table Met_Wenu  2.5   wjets_AnaMonoJet_0
echo " "
Table Met_Wenu  2.5   wjets_AnaMonoJet_1
echo " "
Table Met_Wenu  2.5   wjets_AnaMonoJet_2
echo " "
Table Met_Wenu  2.5   wjets_AnaMonoJet_3
echo " "
Table Met_Wenu  2.5   wjets_AnaMonoJet_4
echo " "
Table Met_Wenu  2.5   wjets_AnaMonoJet_5
echo " "
Table Met_Wenu  2.5   wjets_AnaMonoJet_6
echo " "
Table Met_Wenu  2.5   wjets_AnaMonoJet_7
echo " "
Table Met_Wenu  2.5   wjets_AnaMonoJet_8
echo " "
Table Met_Wenu  2.5   wjets_AnaMonoJet_9
echo " "
Table Met_Wenu  2.5   wjets_AnaMonoJet_10
echo " "
Table Met_Wenu  2.5   wjets_AnaMonoJet_11
echo " "
Table Met_Wenu  2.5   wjets_AnaMonoJet_12
echo " "

echo "|      *Wmunu*   | "
Table Met_Wmnu  2.5   wjets_AnaMonoJet_0
echo " "
Table Met_Wmnu  2.5   wjets_AnaMonoJet_1
echo " "
Table Met_Wmnu  2.5   wjets_AnaMonoJet_2
echo " "
Table Met_Wmnu  2.5   wjets_AnaMonoJet_3
echo " "
Table Met_Wmnu  2.5   wjets_AnaMonoJet_4
echo " "
Table Met_Wmnu  2.5   wjets_AnaMonoJet_5
echo " "
Table Met_Wmnu  2.5   wjets_AnaMonoJet_6
echo " "
Table Met_Wmnu  2.5   wjets_AnaMonoJet_7
echo " "
Table Met_Wmnu  2.5   wjets_AnaMonoJet_8
echo " "
Table Met_Wmnu  2.5   wjets_AnaMonoJet_9
echo " "
Table Met_Wmnu  2.5   wjets_AnaMonoJet_10
echo " "
Table Met_Wmnu  2.5   wjets_AnaMonoJet_11
echo " "
Table Met_Wmnu  2.5   wjets_AnaMonoJet_12
echo " "

echo "|    *Wtaunu*  | "

Table Met_Wtnu  2.5   wjets_AnaMonoJet_0
echo " "
Table Met_Wtnu  2.5   wjets_AnaMonoJet_1
echo " "
Table Met_Wtnu  2.5   wjets_AnaMonoJet_2
echo " "
Table Met_Wtnu  2.5   wjets_AnaMonoJet_3
echo " "
Table Met_Wtnu  2.5   wjets_AnaMonoJet_4
echo " "
Table Met_Wtnu  2.5   wjets_AnaMonoJet_5
echo " "
Table Met_Wtnu  2.5   wjets_AnaMonoJet_6
echo " "
Table Met_Wtnu  2.5   wjets_AnaMonoJet_7
echo " "
Table Met_Wtnu  2.5   wjets_AnaMonoJet_8
echo " "
Table Met_Wtnu  2.5   wjets_AnaMonoJet_9
echo " "
Table Met_Wtnu  2.5   wjets_AnaMonoJet_10
echo " "
Table Met_Wtnu  2.5   wjets_AnaMonoJet_11
echo " "
Table Met_Wtnu  2.5   wjets_AnaMonoJet_12
echo " "




















