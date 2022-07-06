#!usr/bin/ipython3
import re
from collections import Counter
from pprint import pprint

def kasiski_test(text):

	#remove everything but characters 
	text = re.sub(r'\W+', '', text)

	# define max and min lengths
	max_match_length = 25
	min_match_length = 3
	text_length = len(text)

	#initialise lists
	locations = []
	distances= []
	
	#find all duplicate strings	with size between max and min length
	#and find distances between them
	for i in range(text_length):
		locations.append([])
		locations[i] = [list([]) for _ in range(max_match_length+1)]
	
		#count down from largest range to smallest range
		for m in range(max_match_length, min_match_length, -1):
			string = text[i: i+m]

			# find_index where string is located,
			# and find all further indicies
			find_index = text.find(string, 0)
			
			# go through all locations of string
			while find_index != -1:
				locations[i][m].append(find_index)
				find_index =text.find(string, find_index+1)
			
			# calculate distances if more than one string found:
			if len(locations[i][m]) > 1:
				print(text[i:i+m])
				for j in range(1, len(locations[i][m])):
					distances.append(locations[i][m][j] - locations[i][m][0])
				break # found largest string for location i 
	
	pprint(Counter(distances))
	
	return


if __name__ == '__main__':
	""" Carries out Kasiski test on text
	"""
	text = "pb b iwew pb uim zjvioe bawys mjdxv h vpcjbl. ucu b vtkam, ejzmq, dsu iwew, mwmmmw ophi upx wurt pn pgyat bvw su cpag lelzm, owk qlh b ezr, thff, tigvf vpmm paav opbaauu jo qm lv gju lhou co pz mg lou: jb psz o ipjuaa-vpmm, tfk hibb fwhbt dwfxvfu. jb ask o qfzywjhmz zhmur epwk dpyf b xhjavpmm, ispbufl zjlso, xqmz h gijvr qlzmpe ujhgt lvht pb uim xphqu nqwvss. uim wgvf pqmgwk co uw t lbpf-tpthlr ibte dpyf b bnfusm: b dxjf qpnnhjaocmm mmubfm eblocvu afgrs, xjba hhbfmtxv domma, tfk tmpwkk awmfl tfk qbsxxllr, qswoakse xqmz wcmjaawk qibqkk, hbe mwmk hbe mwmk vt qfol xvf ibbl sur dpimk—avf iwutph xba ygur pg dbkphpsa. mzl hvovxd dcvol hf hbe pv, zgpbh gibjsm cvb gga evjbx kafbjoal pbup baw zwef wy los ijte—los ijte, sz omm baw wspqtx xvf nbvr epzft zhmur dbtewk wu—bvw ehbz mqmlss spcgv kcpsa hhlbfe wnl vt ju, nbjzh po wgw zwef igv avfo wg sucuimk. fv upjvz mwgubqkk mcs upx zvpcjb: uwkfppul, thhiswhez, qfmttjz, dbobkalg (mpbl gm hifax), ohfeswuwz (vf iiw oocmf zhgtg efdhllr up kegavft), sbljvfoa, wauwoh-zhgtg, bmt pwys po baw zonf negvf, bol bfksfe wg los tbux hhgtbox. los cfam jvcnt exjl omm wg los mfnm-zhbe tqww (ncjoo bf), mcs upxkl kfsm mzl comg hflg up ptnl kjolhoz, rffx-lwa fpvvw opbepel dvcljvz gcss iql yhfefv, tfk afblhoz pfzwgv, zzpqqgy kcxo bh los sjdxj. avjt phtiwu xil s cssz exds-hp-ew agipju, igv owt oifw dot cizypbt. upx thuhjvlwz vbe tbnlr jo baw usjhpugbfipww gm hif pbds tps bbel cvu wy epbe, bvw hlcqmm vgugjemkwk hifu owym sfaiwjhbctx, fvh potr tlqbvax evgu pn mzla xfzx jpqi, ccm ssgp cmvsbgf upxq uswfz ask ooz iwnlbuvzxk vf ejl tffhijvz musyqmvllr: zpc vgbze umed dvbu i usnujoa pgbze tir gu ooz ynwzhjpv paavpvb mzl ppupxj vt btsbfn vjn. baaz wt b amgym pg pho h pbhobfz vbe ig skjfobnjl, ooe nhmur ijulwst epqgy hbe tirauu uiqgyz omuwzwavfs cgwedfdbxv. os nbg ascs mpam los ofqzzicvsa’ kwzdfdb, uma vf hibflr—xfte, qvi xjte kls ximmzlf if otause bvrlowoh qg los fol."

	kasiski_test(text)

	
	

