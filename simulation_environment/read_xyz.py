import load_atoms

x = load_atoms.read_xyz()
print(len(x))

for atom in x:
	print(atom)
