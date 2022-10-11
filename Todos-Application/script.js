let todoItemsContainer = document.getElementById('todoItemsContainer');
let addBtn = document.getElementById('addBtn');
let saveBtn = document.getElementById('saveBtn');

// let todoList = [
    // {
    //     todoName: 'Learn HTML',
    //     uniqueId: 1
    // },
    // {
    //     todoName: 'Learn CSS',
    //     uniqueId: 2
    // },
    // {
    //     todoName: 'Learn Javascript',
    //     uniqueId: 3
    // }
// ];



function getTodoListFromLocalStorage(){
    let todoList = localStorage.getItem('todoList');
    let parsedTodoList = JSON.parse(todoList);
    if(parsedTodoList === null){
        return [];
    }else{
        return parsedTodoList;
    }
}

let todoList = getTodoListFromLocalStorage();
// let uniqueIDs = [-1];


saveBtn.onclick = function(){
    localStorage.setItem('todoList',JSON.stringify(todoList));
}

function checkedStatus(checkboxId, labelId, todoId){
    let checkboxInput = document.getElementById(checkboxId);
    let label = document.getElementById(labelId);

    // if(checkboxInput.checked === true){
    //     label.classList.add('checked');
    // }else{
    //     label.classList.remove('checked');
    // }

    label.classList.toggle('checked');

    let todoItemIndex = todoList.findIndex(function(eachTodo){
        if(todoId === 'todo' + eachTodo.uniqueId){
            return true;
        }else{
            return false;
        }
    });

    let todoItem = todoList[todoItemIndex];

    if(todoItem.isChecked === true){
        todoItem.isChecked = false;
    }else{
        todoItem.isChecked = true;
    }


}


function onDeleteTodoItem(todoId){
    let todoItem = document.getElementById(todoId);
    todoItemsContainer.removeChild(todoItem);

    let deleteTodoItemIndex = todoList.findIndex(function(eachTodo){
        if ('todo' + eachTodo.uniqueId === todoId){
            return true;
        }else{
            return false;
        }
    });

    todoList.splice(deleteTodoItemIndex,1);
}

function createTodoItem(todo){
    let todoId = 'todo' + todo.uniqueId;
    let checkboxId = 'checkbox' + todo.uniqueId;
    let labelId = 'label' + todo.uniqueId;

    let todoItem = document.createElement('li');
    todoItem.id = todoId;
    todoItem.classList.add('todo-item', 'd-flex', 'flex-row');
    todoItemsContainer.appendChild(todoItem);

    let checkboxInput = document.createElement('input');
    checkboxInput.type = 'checkbox';
    checkboxInput.id = checkboxId;
    checkboxInput.checked = todo.isChecked;


    checkboxInput.onclick = function(){
        checkedStatus(checkboxId, labelId, todoId);
    }

    checkboxInput.classList.add('checkbox-input');
    todoItem.appendChild(checkboxInput);


    let labelContainer = document.createElement('div');
    labelContainer.classList.add('label-container', 'd-flex');
    todoItem.appendChild(labelContainer);

    let labelEl = document.createElement('label');
    labelEl.setAttribute('for', checkboxId);
    labelEl.id = labelId;
    
    labelEl.textContent = todo.todoName;
    labelEl.classList.add('label-element');

    if(todo.isChecked === true){
        labelEl.classList.add('checked');
    }
    

    labelContainer.appendChild(labelEl);

    let deleteContainer = document.createElement('div');
    deleteContainer.classList.add('delete-container');
    labelContainer.appendChild(deleteContainer);

    let deleteIcon = document.createElement('i');
    deleteIcon.classList.add('far', 'fa-trash-alt','delete-icon');
    deleteContainer.appendChild(deleteIcon);

    deleteIcon.onclick = function(){
        onDeleteTodoItem(todoId);
    }

}



function appendTodoItem(inputTextValue){
    let inputText = document.getElementById('inputText');
    inputTextValue = inputText.value;

    if(inputTextValue === ''){
        alert('Enter Valid Input');
        return;
    }else{

        let maxId = localStorage.getItem('MaxIndexId');
        if(maxId === null){
            maxId = -1;
        }
        localStorage.setItem('MaxIndexId', parseInt(maxId) + 1);
        
        let todoListId = localStorage.getItem('MaxIndexId');
        // uniqueIDs.push(todoListId);
    

        let newTodo = {
            todoName: inputTextValue,
            uniqueId: todoListId,
            isChecked: false
        }
        todoList.push(newTodo);
        createTodoItem(newTodo);
    }
  
}

addBtn.onclick = function(){
    appendTodoItem();

    inputText.value = "";
}

for(let todo of todoList){
    createTodoItem(todo);
}

// localStorage.removeItem('todoList');
// localStorage.removeItem('MaxIndexId');
