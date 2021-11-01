import crypt

salt_hash = "rmLMAKBr4gpn2"       

salt = salt_hash[0:2]  

passwd = open('PWD', 'r')
file = passwd.readlines()

for password in file:
    pas = password.strip()
    calculated_salt_hash = crypt.crypt(passwd, salt)
    if calculated_salt_hash == salt_hash:
        print("Found:", pas)


wordfile = open('dictionary', 'r')
lines = wordfile.readlines()

for line in lines:               
    word = line.strip()
    calculated_salt_hash = crypt.crypt(word, salt)
    if calculated_salt_hash == salt_hash:
        print("Found:", word)
        break 
