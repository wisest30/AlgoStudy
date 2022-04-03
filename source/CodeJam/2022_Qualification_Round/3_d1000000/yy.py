import sys 
import numpy as np

def dicek(n,dices):
    n_list=np.arange(1,n+1)
    sorted_dices=sorted(dices)
    dice_idx=0
    n_idx=0
    #print(n_list,sorted_dices)
    while dice_idx < len(dices):
        #print(dice_idx,n_idx)
        if n_idx==n-1 or dice_idx==len(dices)-1: 
            if n_list[n_idx] > sorted_dices[dice_idx]:
                n_idx-=1
            break
        n_each=n_list[n_idx]
        n_dice=sorted_dices[dice_idx]
        if n_each > n_dice:
            dice_idx+=1
        else:
            n_idx+=1
            dice_idx+=1
        
    #print(n_idx)
    return n_list[n_idx]


def get_result(lines):
    test_cases=int(lines[0])
    case_counter=0
    line_counter=0
    for line in lines[1:]:
        line_counter+=1
        if line_counter==1: 
            case_counter+=1
            n=int(line.strip())
        if line_counter==2:
            dice_list=[ int(i) for i in line.strip().split(" ")]
            print("Case #{}: {}".format(case_counter,dicek(n,dice_list)))
            line_counter=0
lines=[]
for line in sys.stdin:
    lines.append(line.strip())
get_result(lines)
