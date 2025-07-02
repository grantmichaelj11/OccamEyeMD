import load_atoms

x = load_atoms.read_xyz("SQOH2ME.xyz")
print(len(x))

for atom in x:
	print(atom)

y = load_atoms.read_pdb("SQOH2ME.xyz")
print(y)





