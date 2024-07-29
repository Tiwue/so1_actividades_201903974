echo 'Introduzca su nombre de usuario de Github:'
read GITHUB_USER
url="https://api.github.com/users/"$GITHUB_USER
echo $url
CUR_Lags="-f -s -S -k"
Json_GitHub=$(curl $CUR_Lags $url)
user_id=$(echo $Json_GitHub | jq ".id")
git_user=$(echo $Json_GitHub | jq ".login")
created_at=$(echo $Json_GitHub | jq ".created_at")
mensaje="Hola "$git_user". User ID: "$user_id". Cuenta fue creada el:"$created_at"."  
fecha=`date +"%Y-%d-%m"`
mkdir -p "/tmp/$fecha"
echo mensaje >> "/tmp/$fecha/saludos.log"
