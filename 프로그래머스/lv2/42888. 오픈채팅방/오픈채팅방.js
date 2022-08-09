const user = {};
const systemMessage = {
    "Enter" : "님이 들어왔습니다.",
    "Leave" : "님이 나갔습니다."
}

function solution(record) {
    let enterLeaveList = [];
    
    record.forEach(log => {
        const [type, userId, nickName] = log.split(' ');
        
        switch(type) {
            case 'Enter' :
                enterLeaveList.push(['Enter', userId]);
                user[userId] = nickName;
                break;
            case 'Leave' :
                enterLeaveList.push(['Leave', userId]);
                break;
            case 'Change' :
                user[userId] = nickName;
                break;
        }
    })

    return enterLeaveList.map(x => getSystemMessage(x[0], x[1]));
}

function getSystemMessage(type, userId) {
    return `${user[userId]}${systemMessage[type]}`
}