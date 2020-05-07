import os

for root, dirs, files in os.walk("."):

    for name in files:
        curr_file = os.path.join(root, name)
        #print(curr_file)
        spl = curr_file.split('@')

        if len(spl) > 1:
            base = spl[0]
            identifier = spl[1]

            base_spl = base.split('.zip')
            #print(base_spl)
            base = base_spl[0] + '_' + identifier

            #print(base)
        
            os.rename(curr_file, base + '.zip')
