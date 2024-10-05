def group_check(st):
    index_lst = []
    spe_lst = set({})
    
    for i in range(len(st)):
        spe_lst.add(st[i])
        
    spe_lst = list(spe_lst)
    
    for i in spe_lst:
        if st.count(i) != 1:
            index_lst.append(st.find(i))
            index_lst.append(st.rfind(i))
            for j in range(index_lst[0], index_lst[1]):
                if st[j] != i:
                    return False
        index_lst.clear()
    return True
    
n = int(input())
str_lst = []
count = 0

for i in range(n):
    str_lst.append(input())
for i in range(n):
    if group_check(str_lst[i]):
        count += 1

print(f"{count}")
