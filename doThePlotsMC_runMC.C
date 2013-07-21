//TString nomPlot[9] = {"denom_pt","TOGCPF_from_TrackerOrGlobal","TOGCPFT_from_TrackerOrGlobal","TOGCPFTIP_from_TrackerOrGlobal","TOGCPFTIPMVA_from_TrackerOrGlobal","TOGCPF_from_TOGclean","TOGCPFT_from_TOGCPF","TOGCPFTIP_from_TOGCPFT","TOGCPFTIPMVA_from_TOGCPFTIP"};
//TString cuts[8] = {"pt", "pt_fine", "eta_sup", "eta_inf", "pt_real_etabin0", "pt_real_etabin1", "vtx", "pt_latinos"};


TFile *myFileA = new TFile("theEfficiencyPlots_mc_All.root");
TFile *myFileB = new TFile("theEfficiencyPlots_mc_RunAB.root");
TFile *myFileC = new TFile("theEfficiencyPlots_mc_RunC.root");
TFile *myFileD = new TFile("theEfficiencyPlots_mc_RunD.root");









drawMyPlot(TString nameCut, TString theText, TString title, float yMin, float yMax){
    
    cout << theText << endl;
    TString theGoodCut = nameCut;
    theGoodCut.ReplaceAll("isSameSign_fail","eventMatched_pass_&_isSameSign_fail");

    
    
	
	TGraphAsymmErrors *theGraph4 = (TGraphAsymmErrors*) myFileA->Get(theGoodCut);
    int inPointsDATA = theGraph4->GetN();
    for (int i = 0 ; i < inPointsDATA; i++){
        cout << "err+" << theGraph4->GetErrorYhigh(i) << "err-" << theGraph4->GetErrorYlow(i) << endl;
        if ( theGraph4->GetErrorYhigh(i)> theGraph4->GetErrorYlow(i)){
            theGraph4->SetPointEYhigh(i,theGraph4->GetErrorYlow(i));
            theGraph4->SetPointEYlow(i,theGraph4->GetErrorYlow(i));
        }
        else {
            theGraph4->SetPointEYhigh(i,theGraph4->GetErrorYhigh(i));
            theGraph4->SetPointEYlow(i,theGraph4->GetErrorYhigh(i));
        }
    }
    
    TGraphAsymmErrors *theGraph4B = (TGraphAsymmErrors*) myFileB->Get(theGoodCut);
    int inPointsDATA = theGraph4B->GetN();
    for (int i = 0 ; i < inPointsDATA; i++){
        cout << "err+" << theGraph4B->GetErrorYhigh(i) << "err-" << theGraph4B->GetErrorYlow(i) << endl;
        if ( theGraph4B->GetErrorYhigh(i)> theGraph4B->GetErrorYlow(i)){
            theGraph4B->SetPointEYhigh(i,theGraph4B->GetErrorYlow(i));
            theGraph4B->SetPointEYlow(i,theGraph4B->GetErrorYlow(i));
        }
        else {
            theGraph4B->SetPointEYhigh(i,theGraph4B->GetErrorYhigh(i));
            theGraph4B->SetPointEYlow(i,theGraph4B->GetErrorYhigh(i));
        }
    }
    
    TGraphAsymmErrors *theGraph4C = (TGraphAsymmErrors*) myFileC->Get(theGoodCut);
    int inPointsDATA = theGraph4C->GetN();
    for (int i = 0 ; i < inPointsDATA; i++){
        cout << "err+" << theGraph4C->GetErrorYhigh(i) << "err-" << theGraph4C->GetErrorYlow(i) << endl;
        if ( theGraph4C->GetErrorYhigh(i)> theGraph4C->GetErrorYlow(i)){
            theGraph4C->SetPointEYhigh(i,theGraph4C->GetErrorYlow(i));
            theGraph4C->SetPointEYlow(i,theGraph4C->GetErrorYlow(i));
        }
        else {
            theGraph4C->SetPointEYhigh(i,theGraph4C->GetErrorYhigh(i));
            theGraph4C->SetPointEYlow(i,theGraph4C->GetErrorYhigh(i));
        }
    }
    
    TGraphAsymmErrors *theGraph4D = (TGraphAsymmErrors*) myFileD->Get(theGoodCut);
    int inPointsDATA = theGraph4D->GetN();
    for (int i = 0 ; i < inPointsDATA; i++){
        cout << "err+" << theGraph4D->GetErrorYhigh(i) << "err-" << theGraph4D->GetErrorYlow(i) << endl;
        if ( theGraph4D->GetErrorYhigh(i)> theGraph4D->GetErrorYlow(i)){
            theGraph4D->SetPointEYhigh(i,theGraph4D->GetErrorYlow(i));
            theGraph4D->SetPointEYlow(i,theGraph4D->GetErrorYlow(i));
        }
        else {
            theGraph4D->SetPointEYhigh(i,theGraph4D->GetErrorYhigh(i));
            theGraph4D->SetPointEYlow(i,theGraph4D->GetErrorYhigh(i));
        }
    }

    
    int inPoints = theGraph4->GetN();
    double x,y;
    double x2, y2;    
    theGraph4->GetPoint(0, x, y);
    theGraph4->GetPoint(inPoints-1, x2, y2);
    
    float lowLim = x-theGraph4->GetErrorXlow(0);
    float highLim = x2+theGraph4->GetErrorXhigh(inPoints-1);
    
    
	TCanvas *c0 = new TCanvas("c0","coucou",600, 600);
	c0->SetFillColor(0);
	theGraph4->SetMinimum(yMin);
	theGraph4->SetMaximum(yMax);
    
	theGraph4->SetMarkerStyle(22);
	theGraph4->SetMarkerColor(kGreen-6);
	theGraph4->GetYaxis()->SetTitle("#epsilon");
	theGraph4->SetMarkerSize(1.5);
    theGraph4->GetXaxis()->SetRangeUser(lowLim,highLim);
	theGraph4->Draw("AP");
	theGraph4B->SetMarkerStyle(22);
	theGraph4B->SetMarkerColor(kMagenta-6);
	theGraph4B->SetMarkerSize(1.5);
	theGraph4B->Draw("P:same");
    theGraph4C->SetMarkerStyle(22);
	theGraph4C->SetMarkerColor(kBlue-6);
	theGraph4C->SetMarkerSize(1.5);
	theGraph4C->Draw("P:same");
    theGraph4D->SetMarkerStyle(22);
	theGraph4D->SetMarkerColor(kOrange-6);
	theGraph4D->SetMarkerSize(1.5);
	theGraph4D->Draw("P:same");


    
	TLatex theLatex;
	theLatex.SetNDC();
	theLatex.SetTextSize(0.03);
	theLatex.DrawLatex(0.06,0.92, title);
	
	theLatex.DrawLatex(0.55,0.92, theText);
    
	TLegend *t = new TLegend(0.66,0.16,0.87,0.35);
	t->SetFillColor(0);
	t->SetLineColor(0);
	t->AddEntry(theGraph4,"all 2012","P");
	t->AddEntry(theGraph4B,"runAB","P");
	t->AddEntry(theGraph4C,"runC","P");
	t->AddEntry(theGraph4D,"runD","P");
    
	t->Draw();
    
    TLine *line = new TLine(lowLim,1,highLim,1);
    line->SetLineStyle(2);
 //   line->Draw("same");
    
	
	c0->Print("compMC/plot_"+nameCut+"MC.png");
    
}

doADraw3bins(TString name, TString title){
    cout << "on va plotter le plot " << name << endl;
    drawMyPlot(name, "|#eta| <0.9",title,0.6,1.05);
    name.ReplaceAll("bin0","bin1");
	drawMyPlot(name, "0.9 <|#eta| < 1.2",title,0.6,1.05);
    name.ReplaceAll("bin1","bin2");
	drawMyPlot(name, "1.2 <|#eta| < 2.4",title,0.6,1.05);
    
}


doADraw4bins(TString name, TString title){
    cout << "on va plotter le plot " << name << endl;
    drawMyPlot(name, "|#eta| < 0.8",title,0,1.2);
    name.ReplaceAll("bin0","bin1");
	drawMyPlot(name, "0.8 <|#eta| < 1.479",title,0,1.2);   
    name.ReplaceAll("bin1","bin2");
	drawMyPlot(name, "1.479 <|#eta| < 2.0",title,0,1.2);
    name.ReplaceAll("bin2","bin3");
	drawMyPlot(name, "2.0 <|#eta| < 2.5",title,,0,1.2);
    
}

doADraw2bins(TString name, TString title){
    drawMyPlot(name, "|#eta| < 1.48",title,0,1.2);
    name.ReplaceAll("bin0","bin1");
	drawMyPlot(name, "1.48 <|#eta| < 2.4",title,0,1.2);       
}


doADraw2binsPOG(TString name, TString title){
    drawMyPlot(name, "|#eta| < 1.2",title,0.8,1.1);
    name.ReplaceAll("bin0","bin1");
	drawMyPlot(name, "1.2 <|#eta| < 2.4",title,0.8,1.1);       
}

doADraw5bins(TString name, TString title){
    cout << "on va plotter le plot " << name << endl;
    drawMyPlot(name, "|SC #eta| < 0.8",title,0,0.9);
    name.ReplaceAll("bin0","bin1");
	drawMyPlot(name, "0.8 <|SC #eta| < 1.4442",title,0,0.9);
    name.ReplaceAll("bin1","bin2");
	drawMyPlot(name, "1.4442 <|SC #eta| < 1.556",title,0,0.9);
    name.ReplaceAll("bin2","bin3");
	drawMyPlot(name, "1.556 <|SC #eta| < 2.0",title,0,0.9);
    name.ReplaceAll("bin3","bin4");
	drawMyPlot(name, "2.0 <|SC #eta| < 2.5",title,0,0.9);
    
}


doThePlotsMC_runMC(){
	gStyle->SetOptStat(0);
	gStyle->SetOptTitle(0);


    
    doADraw5bins("passFO_BDT_ISO_pt_pt_PLOT_absSCeta_bin0_&_isSameSign_fail","Hww selection");
    doADraw5bins("passFO_ptFO_pt_PLOT_absSCeta_bin0_&_isSameSign_fail","Preselection");
    doADraw5bins("passFO_BDT_ISO_ptNM1ID_pt_PLOT_absSCeta_bin0_&_isSameSign_fail_&_passFO_ISO_pass","N-1 ID");
    doADraw5bins("passFO_BDT_ISO_ptNM1ISO_pt_PLOT_absSCeta_bin0_&_isSameSign_fail_&_passFO_BDT_pass","N-1 ISO");
    
}





