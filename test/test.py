import corelink

p = corelink.Person("Kaikai", 20)

print(p.get_person())

age = p.get_age()
print(str(age))

print(corelink.hello())
corelink.hello_world()
 
p.change_name("Arthur")
print(p.get_person())