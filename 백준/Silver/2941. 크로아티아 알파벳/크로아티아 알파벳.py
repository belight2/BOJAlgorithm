croatia_spe = [ "c=", "c-", "d-", "lj", "nj", "s=", "z=","dz="]
count = 0
st = input()
result = len(st)

for i in croatia_spe:
   count += st.count(i)
result -= count

print(f"{result}")