document.getElementById('btn').addEventListener('click',showGithubUserProfile)

function showGithubUserProfile(){
    let username = document.getElementById('gusername').value

    let url = 'https://api.github.com/users/'+username
    fetch(url).then(res=>res.json()).then(data=>{
        if(data.message){
            document.getElementById('res').innerHTML = `
               <h3>Profile Not Found</h3>
            `
        }else{
            document.getElementById('res').innerHTML = `
            <img src="${data.avatar_url}"
            style="width:100%">
            <p>${data.name} (${data.login})</p>
            <p>${data.bio}</p>
            `
        }
    }).catch(e=>{
        console.log(e)
    })
}
