import Editor from './Editor'
import { useRef } from 'react';
import axios from 'axios';

function App() {
  const codemirrorRef = Array.from({length: 4}, () => useRef(null));
  
  const handleCompile = () => {
    console.log(codemirrorRef[0].current.editor.getValue());
    const code = codemirrorRef[0].current.editor.getValue();
    axios.post(`${import.meta.env.VITE_API_URL}/compile`, { code },
      {
        headers: {
          'Content-Type': 'application/json',
        }
      }
    ).then((response) => {
      console.log(response.data)
      const { quad, errors, symbolTable } = response.data;
      codemirrorRef[1].current.editor.setValue(quad);
      codemirrorRef[2].current.editor.setValue(errors);
      codemirrorRef[3].current.editor.setValue(symbolTable);
    }).catch((error) => {
      console.error(error);
    });
  }

  return (
    <>
      <button className='absolute mt-2 right-2 px-2 py-1 bg-[#333] text-white rounded-md' onClick={handleCompile}>Compile</button>
        <div className='overflow-hidden flex flex-col items-center justify-center text-left bg-[#272822]'>
          <Editor title={"C/C++ Compiler"} readOnly={false} codemirrorRef={codemirrorRef[0]}/>
          <div className='flex items-center justify-around w-full'>
            <Editor title={"Quadruples"}  readOnly={true} codemirrorRef={codemirrorRef[1]}/>
            <Editor title={"Errors"} readOnly={true} codemirrorRef={codemirrorRef[2]}/>
            <Editor title={"Symbol Table"} readOnly={true} codemirrorRef={codemirrorRef[3]}/>
          </div>
        </div>
      </>
  )
}

export default App
