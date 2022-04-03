import sys

def puch_card(R,C):
    #result=[[""]*(2*C+1)]*(2*R+1)
    result=[["" for x in range(2*C+1)] for x in range(2*R+1)]
    C_max=2*C+1
    R_max=2*R+1
    for r_idx in range(R_max):
    	for c_idx in range(C_max):
    		#print(r_idx,c_idx,result[r_idx],result[r_idx][c_idx])
    		if r_idx<2:
    			if c_idx<2: 
    				result[r_idx][c_idx]="."
    			elif r_idx==0:
    				if c_idx%2==0:result[r_idx][c_idx]="+"
    				elif c_idx%2!=0:result[r_idx][c_idx]="-"
    			elif r_idx==1:
    				if c_idx%2==0:result[r_idx][c_idx]="|"
    				elif c_idx%2!=0:result[r_idx][c_idx]="."
    		elif r_idx%2==0:
    			if c_idx%2==0:result[r_idx][c_idx]="+"
    			elif c_idx%2!=0:result[r_idx][c_idx]="-"
    		else:
    			if c_idx%2==0:result[r_idx][c_idx]="|"
    			elif c_idx%2!=0:result[r_idx][c_idx]="."
    		#print(result)
    
    for each in result:
    	print("".join(each))
    
    
def get_result(lines):
    test_cases=int(lines[0])
    case_counter=0
    for line in lines[1:]:
        case_counter+=1
        print("Case #{}".format(case_counter))
        R,C=line.strip().split(" ")
        R,C=int(R),int(C)
        puch_card(R,C)
lines=[]	
for line in sys.stdin:
    lines.append(line.strip())
get_result(lines)
