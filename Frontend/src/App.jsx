import { useRef } from 'react';
import axios from 'axios';
import Output from './Output';
import Editor from './Editor'
import PlayArrowOutlinedIcon from '@mui/icons-material/PlayArrowOutlined';

function App() {
  const codemirrorRef = Array.from({ length: 4 }, () => useRef(null));

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

    <div className='overflow-hidden h-screen w-full flex flex-col items-center text-left bg-[#171717]'>
      <div className='w-full mt-[6px] flex items-center flex-row h-[65px] bg-[#252526]'>
        <h1 className='ml-6 text-gray-300 text-[14px] tracking-wider font-light'>IM++</h1>
        <svg className='w-4 h-[14px] text-gray-200' xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 24 24" strokeWidth="1.5" stroke="currentColor">
          <path strokeLinecap="round" strokeLinejoin="round" d="m8.25 4.5 7.5 7.5-7.5 7.5" />
        </svg>
        <h1 className='text-gray-300 text-[14px] tracking-wider font-light'>src</h1>
        <svg className='w-4 h-[14px] text-gray-200' xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 24 24" strokeWidth="1.5" stroke="currentColor">
          <path strokeLinecap="round" strokeLinejoin="round" d="m8.25 4.5 7.5 7.5-7.5 7.5" />
        </svg>
        <h1 className='text-gray-300 text-[14px] tracking-wider font-light'>index.imx</h1>
        <div onClick={handleCompile} className='flex ml-4 bg-[#171717] hover:bg-inherit pr-2 h-full flex-row cursor-pointer items-center'>
          <PlayArrowOutlinedIcon className=' mt-[1px] text-gray-300' />
          <h1 className='text-gray-300 text-[13px] ml-[1px] mt-[1px]'>Run</h1>
        </div>
      </div>
      <Editor codemirrorRef={codemirrorRef[0]} />
      <div className='flex flex-row border-t h-fit min-h-[335px] w-full'>
        <Output title={"Quadruples"} codemirrorRef={codemirrorRef[1]} />
        <Output title={"Errors"} codemirrorRef={codemirrorRef[2]} />
        <Output title={"Symbol Table"} codemirrorRef={codemirrorRef[3]} />
      </div>
    </div>

  )
}


export default App
