import yaml

i = 1
def callback():
	global i
	print i
	data = dict(A = 1, B = 2, C = 3)
	if i == 1:
		with open('data.yaml','w') as file:
			yaml.dump(data, file, default_flow_style=False)
	i = i +1

for i in range(2):
	callback()
